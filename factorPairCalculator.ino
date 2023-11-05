//factor pair calculator
void factPairCalculator()
{
  bool backPressed{false}; //lets us break out of the outer while loop from inside functions
  while (!backPressed) {

  uint16_t enteredNum{0};
  enteredNum = getNumInput(backPressed);

    //lcd.clear();
    // uint16_t enteredNum{0};
    // lcd.print(enteredNum);
    // while (!backPressed) { //loop for getting input
    //   //TODO: account for max num size
    //   char pressedKey = keypad.getKey();
    //   int pressedNum = pressedKey - 48; //subtracts 48 to get the ascii digits down to their actual values(0 is ascii 48, etc)
    //   if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredNum && !pressedNum)) {
    //     //if (((enteredNum * 10) + pressedNum) > 65535) { //arduino is weird with ints more then 16 bit
    //     if (enteredNum > ((65535 - pressedNum) / 10) ) { //arduino is weird with ints more then 16 bit, so don't allow them
    //       lcd.clear();
    //       lcd.print("Max num size");

    //       while (!digitalRead(enterButton)) {}
    //       delay(50);
    //       while (digitalRead(enterButton)) {}
    //       delay(50);

    //       lcd.clear();
    //       lcd.print(enteredNum);
    //     } else {
    //       enteredNum = (enteredNum * 10) + pressedNum;
    //       lcd.clear();
    //       lcd.print(enteredNum);
    //     }
    //   }

    //   if (pressedKey)
    //     delay(50); //debounce delay

    //   if (digitalRead(backButton)) {
    //     delay(50);
    //     backPressed = true;
    //   }

    //   if (digitalRead(enterButton)) { //enteredNum has to be not 0
    //     while (digitalRead(enterButton)) {}
    //     if (enteredNum) {
    //       delay(50);
    //       break;
    //     } else {
    //       lcd.clear();
    //       lcd.print("Must enter");
    //       lcd.setCursor(0, 1);
    //       lcd.print("number");
          
    //       while (!digitalRead(enterButton)) {}
    //       while (digitalRead(enterButton)) {}
    //       delay(50);
    //       lcd.clear();
    //       lcd.print(enteredNum);
    //     }
    //   }
      
    //   if (digitalRead(clearButton)) {
    //     delay(50);
    //     while (digitalRead(clearButton)) {}
    //     delay(50);
    //     enteredNum = 0;
    //     lcd.clear();
    //     lcd.print(enteredNum);
    //   }

    //   if (digitalRead(deleteButton)) {
    //     delay(50);
    //     enteredNum /= 10; //integer division
    //     lcd.clear();
    //     lcd.print(enteredNum);
    //     while (digitalRead(deleteButton)) {}
    //     delay(50);
    //   }
    //   //check for delete
    // }

    int page{0};
    printFactors(enteredNum, page);

    while (!backPressed) {
      
      if (digitalRead(deleteButton)) {
        delay(50);
        ++page;
        if (page > ((numFactors(enteredNum) - 1) / 6))
          page = 0;
        printFactors(enteredNum, page);
        while (digitalRead(deleteButton)) {}
        delay(50);
      }
      
      if (digitalRead(clearButton) || digitalRead(enterButton)) {
        delay(50);
        lcd.clear();
        enteredNum = 0;
        lcd.print(enteredNum);
        while (digitalRead(clearButton) || digitalRead(enterButton)) {}
        delay(50);
        break;
      }

      if (digitalRead(backButton)) {
        delay(50);
        while (digitalRead(backButton)) {}
        backPressed = true;
      }
    }    
  }
}

void printFactors(int factor, int page)
{ //max number we would need to display is 5 digits(65535), so we split the space up in groups of 5
  page *= 6; //so we only have to increase page by one in the logic above
  lcd.clear(); 

  for (int i = 0; i < 6; ++i) {
    lcd.setCursor((i / 2 * 5), (i % 2));
    if (getFactor(factor, (page + i)))
      lcd.print(getFactor(factor, (page + i)));
  }
}

int numFactors(int factor)
{
    int amountFactors{0};
    for (int i = 1; (i <= (factor / 2)) && (i <= (factor / i)); ++i) {
        if (!(factor % i)) {
            amountFactors += 2;
        }
    }
    return amountFactors;
}

uint getFactor(uint16_t composite, int numFactor)
{
    int currentFactor{-1}; //causes the first valid factor to set it to zero, so we can start from 0 instead of 1
    for (uint i = 1; (i <= (composite / 2)) && (i <= (composite / i)); ++i) {
        if (!(composite % i)) {
            if (++currentFactor == numFactor) //i is the smaller factor
                return i;
            else if (++currentFactor == numFactor)
                return (composite / i);
        }
    }
    return 0;
}