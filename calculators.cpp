#include <Arduino.h>
#include "io.h"

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
                while (digitalRead(deleteButton)) {
                }
                delay(50);
            }

            if (digitalRead(clearButton) || digitalRead(enterButton)) {
                delay(50);
                lcd.clear();
                enteredNum = 0;
                lcd.print(enteredNum);
                while (digitalRead(clearButton) || digitalRead(enterButton)) {
                }
                delay(50);
                break;
            }

            if (digitalRead(backButton)) {
                delay(50);
                while (digitalRead(backButton)) {
                }
                backPressed = true;
            }
        }
    }
}

int quadCalc()
{

	//get a, a isn't 0
	//get b
	//get c

	//assign to struct

	//call simplifier

	//handle different outputs


	return 0;
}