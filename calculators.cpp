#include <Arduino.h>
#include "io.h"
#include "main.h"
#include "math.h"

void factPairCalc()
{
    bool backPressed{false}; //lets us break out of the outer while loop from inside functions
    while (!backPressed) {

        uint16_t enteredNum{0};
        enteredNum = getNumInput(backPressed);

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