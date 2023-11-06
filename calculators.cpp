#include <Arduino.h>
#include "calculators.h"
#include "io.h"
#include "main.h"
#include "math.h"

void squareSimplifier()
{
	bool backPressed{false}; //lets us break out of the inner while loops
	while (!backPressed) {
		Square square{0, 0};
		write(square.coef);

		square.coef = getNumInput<int>(backPressed);
		if (!square.coef)
			continue;

		square.root = getNumInput<int>(backPressed, "r:");
		if (!square.root)
			continue;

		//if (backPressed)
		//	break; //band aid fix, will change most likely when implementing io functions

		square = simplifySquare(square);

		//logic to print expression
		if (square.root == 1) //TODO: restructure this so that we only have one print for each given thing
			write(square.coef);
		else if (square.coef == 1)
			write('r', square.root);
		else
			write(square.coef, 'r', square.root);

		idleMenu(backPressed);
	}
}

void factPairCalc()
{
	bool backPressed{false}; //lets us break out of the outer while loop from inside functions
	while (!backPressed) {

		unsigned int enteredNum{0};
		enteredNum = getNumInput<unsigned int>(backPressed);
		if (!enteredNum)
			continue;

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
			enteredNum = 0;
			write(enteredNum);
			return; //breaks out of the inner loop, but not the outer one
		case clearButton:
			--page;
			if (page < 0)
				page = ((numFactors(enteredNum) - 1) / 6);
			printFactors(enteredNum, page);
			break;
		case deleteButton:
			++page;
			if (page > static_cast<int>(((numFactors(enteredNum) - 1) / 6)))
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