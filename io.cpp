#include <Arduino.h>
#include "main.h"

void print(String topText, String bottomText = "")
{
    lcd.clear();
    lcd.print(topText);
    lcd.setCursor(0, 1);
    lcd.print(bottomText);
}

//TODO: replace all input with this function
bool input(int button)
{
    if ((button < 2) || (button > 13))
        return false;

    if (!digitalRead(button))
        return false;

    delay(50);
    while (digitalRead(button));
    delay(50);
    return true;
}

void waitForButton(int button0, int button1 = 0, int button2 = 0, int button3 = 0)
{
    while (!input(button0) || !input(button1) || !input(button2) || !input(button3));
    //while (!digitalRead(button));
    //delay(50);
    //while (digitalRead(button));
    //delay(50);
}

int validateNumInput(char pressedKey, unsigned int enteredNum)
{
    int pressedNum = pressedKey - 48; //subtracts 48 to get the ascii digits down to their actual values(0 is ascii 48, etc)
    if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredNum && !pressedNum)) {
        if (enteredNum > ((65535 - pressedNum) / 10)) { //arduino is weird with ints more then 16 bit, so don't allow them
            print("Max num size");

            waitForButton(enterButton);

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

int getNumInput(bool& backPressed)
{
    lcd.clear();
    uint16_t enteredNum{0};
    lcd.print(enteredNum);
    while (!backPressed) {

        char pressedKey = keypad.getKey();
        enteredNum = validateNumInput(pressedKey, enteredNum);

        if (pressedKey)
            delay(50); //debounce delay

        if (input(backButton))
            backPressed = true;

        if (input(enterButton)) {

            if (enteredNum) {
                break;
            } else {
                print("Must enter", "number");
                waitForButton(enterButton);
                lcd.clear();
                lcd.print(enteredNum);
            }
        }

        if (digitalRead(clearButton)) {
            delay(50);
            while (digitalRead(clearButton)) {
            }
            delay(50);
            enteredNum = 0;
            lcd.clear();
            lcd.print(enteredNum);
        }

        if (digitalRead(deleteButton)) {
            delay(50);
            enteredNum /= 10;
            lcd.clear();
            lcd.print(enteredNum);
            while (digitalRead(deleteButton)) {
            }
            delay(50);
        }
    }

    return enteredNum;
}