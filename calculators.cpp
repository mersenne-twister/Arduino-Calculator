#include <Arduino.h>
#include "calculators.h"
#include "io.h"
#include "main.h"
#include "math.h"

void factPairCalc()
{
	bool backPressed{false}; //lets us break out of the outer while loop from inside functions
	while (!backPressed) {

		unsigned int enteredNum{0};
		enteredNum = getNumInput(backPressed);

		factorsMenu(backPressed, enteredNum);
	}
}

void factorsMenu(bool& backPressed, unsigned int enteredNum)
{
	int page{0};
	printFactors(enteredNum, page);

	while (!backPressed) {
		switch (isInput()) {
		case backButton:
			backPressed = true;
			break;
		case enterButton:
		case clearButton:
			enteredNum = 0;
			write(enteredNum);
			waitForButton(enterButton, clearButton);
			return; //breaks out of the inner loop, but not the outer one
		case deleteButton:
			++page;
			if (page > ((numFactors(enteredNum) - 1) / 6))
				page = 0;
			printFactors(enteredNum, page);
			break;
		default:
			break;
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