//factor pair calculator
void factPairCalculator() {
  bool backPressed{false};
  while (!backPressed) {
    lcd.clear();
    uint16_t enteredNum{0};
    lcd.print(enteredNum);
    while (true) { //loop for getting input

      //TODO: account for max num size
      char pressedKey = keypad.getKey();
      int pressedNum = pressedKey - 48; //subtracts 48 to get the ascii digits down to their actual values(0 is ascii 48, etc)
      if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredNum && !pressedNum)) {
        //if (((enteredNum * 10) + pressedNum) > 65535) { //arduino is weird with ints more then 16 bit
        if (enteredNum > ((65535 - pressedNum) / 10) ) { //arduino is weird with ints more then 16 bit, so don't allow them
          lcd.clear();
          lcd.print("Max num size");

          while (!digitalRead(enterButton)) {}
          delay(50);
          while (digitalRead(enterButton)) {}
          delay(50);

          lcd.clear();
          lcd.print(enteredNum);
        } else {
          enteredNum = (enteredNum * 10) + pressedNum;
          lcd.print(pressedNum);
        }
      }

      if (pressedKey)
        delay(50); //debounce delay

      if (digitalRead(backButton)) {
        delay(50);
        backPressed = true;
        break;
      }

      if (digitalRead(enterButton)) { //enteredNum has to be not 0
        while (digitalRead(enterButton)) {}
        if (enteredNum) {
          delay(50);
          break;
        } else {
          lcd.clear();
          lcd.print("Must enter");
          lcd.setCursor(0, 1);
          lcd.print("number");
          
          while (!digitalRead(enterButton)) {}
          while (digitalRead(enterButton)) {}
          delay(50);
          lcd.clear();
          lcd.print(enteredNum);
        }
      }
      
      if (digitalRead(clearButton)) {
        delay(50);
        while (digitalRead(clearButton)) {}
        delay(50);
        enteredNum = 0;
        lcd.clear();
        lcd.print(enteredNum);
      }

      if (digitalRead(deleteButton)) {
        delay(50);
        enteredNum /= 10; //integer division
        lcd.clear();
        lcd.print(enteredNum);
        while (digitalRead(deleteButton)) {}
        delay(50);
      }
      //check for delete
    }
    //do math

    //display number
    //check for back clear, enter, or delete to cycle through factor
  }
}