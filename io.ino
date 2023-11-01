int getNumInput(bool& backPressed) //I reallyyyyyy hope this works
{
    lcd.clear();
    uint16_t enteredNum{0};
    lcd.print(enteredNum);
    while (true) {

        char pressedKey = keypad.getKey();
        enteredNum = validateNumInput(pressedKey, enteredNum);
        // int pressedNum = pressedKey - 48; //subtracts 48 to get the ascii digits down to their actual values(0 is ascii 48, etc)
        // if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredNum && !pressedNum)) {
        //     if (enteredNum > ((65535 - pressedNum) / 10) ) { //arduino is weird with ints more then 16 bit, so don't allow them
        //         lcd.clear();
        //         lcd.print("Max num size");

        //         while (!digitalRead(enterButton)) {}
        //         delay(50);
        //         while (digitalRead(enterButton)) {}
        //         delay(50);

        //         lcd.clear();
        //         lcd.print(enteredNum);
        //     } else {
        //         enteredNum = (enteredNum * 10) + pressedNum;
        //         lcd.clear();
        //         lcd.print(enteredNum);
        //     }
        // }

        if (pressedKey)
            delay(50); //debounce delay

        if (input(backButton))
            backPressed = true;
        // if (digitalRead(backButton)) {
        //     delay(50);
        //     backPressed = true;
        // }

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
    }

    return enteredNum;
}

int validateNumInput(int pressedKey, int enteredNum)
{
    int pressedNum = pressedKey - 48; //subtracts 48 to get the ascii digits down to their actual values(0 is ascii 48, etc)
    if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredNum && !pressedNum)) {
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
            lcd.clear();
            lcd.print(enteredNum);
        }
    }

    return enteredNum;
}

//TODO: replace all input with this function
bool input(int const button)
{
    if (!digitalRead(button))
        return false;

    delay(50);
    while (digitlRead(button)) {}
    delay(50);
    return true;
}