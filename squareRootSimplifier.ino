void squareSimplifier()
{
  bool backPressed{false}; //lets us break out of the inner while loops
  while (!backPressed) {
    lcd.clear();
    uint16_t enteredCof{0}; //entered coefficient
    uint16_t enteredRoot{0};
    lcd.print(enteredCof);

    while (!backPressed) { //loop for getting coefficient

      //TODO: account for max num size
      char pressedKey = keypad.getKey();
      int pressedNum = pressedKey - 48; //subtracts 48 to get the ascii digits down to their actual values(0 is ascii 48, etc)
      if ((pressedNum >= 1) && (pressedNum <= 9) && !(!enteredCof && !pressedNum)) {
        //if (((enteredNum * 10) + pressedNum) > 65535) { //arduino is weird with ints more then 16 bit
        if (enteredCof > ((65535 - pressedNum) / 10) ) { //arduino is weird with ints more then 16 bit, so don't allow them
          lcd.clear();
          lcd.print("Max num size");

          while (!digitalRead(enterButton)) {}
          delay(50);
          while (digitalRead(enterButton)) {}
          delay(50);

          lcd.clear();
          lcd.print(enteredCof);
        } else {
          enteredCof = (enteredCof * 10) + pressedNum;
          lcd.clear();
          lcd.print(enteredCof);
        }
      }

      if (pressedKey)
        delay(50); //debounce delay

      if (digitalRead(backButton)) {
        delay(50);
        backPressed = true;
      }

      if (digitalRead(enterButton)) { //enteredNum has to be not 0
        while (digitalRead(enterButton)) {}
        delay(50);
        if (enteredCof) {
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
          lcd.print(enteredCof);
        }
      }
      
      if (digitalRead(clearButton)) {
        delay(50);
        while (digitalRead(clearButton)) {}
        delay(50);
        enteredCof = 0;
        lcd.clear();
        lcd.print(enteredCof);
      }

      if (digitalRead(deleteButton)) {
        delay(50);
        enteredCof /= 10; //integer division
        lcd.clear();
        lcd.print(enteredCof);
        while (digitalRead(deleteButton)) {}
        delay(50);
      }
    }

    lcd.clear();
    lcd.print("r:");
    lcd.print(enteredRoot);

    while (!backPressed) { //loop for getting root

      //TODO: account for max num size
      char pressedKey = keypad.getKey();
      int pressedNum = pressedKey - 48; //subtracts 48 to get the ascii digits down to their actual values(0 is ascii 48, etc)
      if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredRoot && !pressedNum)) {
        //if (((enteredNum * 10) + pressedNum) > 65535) { //arduino is weird with ints more then 16 bit
        if (enteredRoot > ((65535 - pressedNum) / 10) ) { //arduino is weird with ints more then 16 bit, so don't allow them
          lcd.clear();
          lcd.print("Max num size");

          while (!digitalRead(enterButton)) {}
          delay(50);
          while (digitalRead(enterButton)) {}
          delay(50);

          lcd.clear();
          lcd.print("r:");
          lcd.print(enteredRoot);
        } else {
          enteredRoot = (enteredRoot * 10) + pressedNum;
          lcd.clear();
          lcd.print("r:");
          lcd.print(enteredRoot);
        }
      }

      if (pressedKey)
        delay(50); //debounce delay

      if (digitalRead(backButton)) {
        delay(50);
        backPressed = true;
      }

      if (digitalRead(enterButton)) { //enteredNum has to be not 0
        while (digitalRead(enterButton)) {}
        delay(50);
        if (enteredRoot) {
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
          lcd.print("r:");
          lcd.print(enteredRoot);
        }
      }
      
      if (digitalRead(clearButton)) {
        delay(50);
        while (digitalRead(clearButton)) {}
        delay(50);
        enteredCof = 0;
        enteredRoot = 0;
        lcd.clear();
        lcd.print("r:");
        lcd.print(enteredCof);
      }

      if (digitalRead(deleteButton)) {
        delay(50);
        enteredRoot /= 10; //integer division
        lcd.clear();
        lcd.print("r:");
        lcd.print(enteredRoot);
        while (digitalRead(deleteButton)) {}
        delay(50);
      }
    }

    if (cleanSqrt(enteredRoot)) { //logic to simplify expression
      enteredCof = cleanSqrt(enteredRoot);
      enteredRoot = 1;
    } else {
      for (uint16_t i = (numFactors(enteredRoot) - 1); i > 2; --i) {
          uint16_t factor{getFactor(enteredRoot, static_cast<int>(i))};

          if (!(enteredRoot % factor))
              if (cleanSqrt(factor)) {
                  enteredRoot /= factor;
                  enteredCof *= cleanSqrt(factor);
              }
      }
    }

    lcd.clear();

    //logic to print expression
    if (enteredRoot == 1) //TODO: restructure this so that we only have one print for each given thing
      lcd.print(enteredCof);
    else if (enteredCof == 1) {
      lcd.print('r');
      lcd.print(enteredRoot);
    } else {
    lcd.print(enteredCof);
    lcd.print('r');
    lcd.print(enteredRoot);
    }

    while (!backPressed) {
      
      if (digitalRead(clearButton) || digitalRead(enterButton)) {
        lcd.clear();
        lcd.print(0);
        while (digitalRead(clearButton) || digitalRead(enterButton)) {}
        delay(50);
        enteredCof = 0;
        enteredRoot = 0;
        break;
      }

      if (digitalRead(backButton)) {
        while (digitalRead(backButton)) {}
        delay(50);
        backPressed = true;
      }

      //check for delete(uhhh make it delete stuff from the answer? then enter puts the stuff back?)(for now it'll do nothing)

      


    }
  }



}

uint16_t cleanSqrt(uint16_t num)
{
    for (int16_t i = 1; i*i <= num; ++i) {
        if ((i * i) == num)
            return i;
    }
    return 0;
}