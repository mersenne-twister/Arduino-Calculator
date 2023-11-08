#include <Arduino.h>
#include "calculators.h"
#include "io.h"
#include "main.h"
#include "math.h"

void pythTheoCalc()
{ //TODO: FIX INTEGER OVERFLOW
	//TODO: add actual type safety lol
	bool backPressed{false};
	while (!backPressed) {
	//unsigned ints cause we won't ever be getting


	//get a
		unsigned int a{getUnsignedInput(backPressed, "a:")}; //all 3 calls int originally
		a = (a * a);

		unsigned int b{0};
		unsigned int c{0};
		unsigned int x{};
		while (!b && !c) {
			b = getUnsignedInput(backPressed, "b:", 0);
			if (!b) {
				c = getUnsignedInput(backPressed, "c:", 0);
				if (!c)
					continue;
				x = ((c * c) - a);
			} else
				x = (a + (b * b));
		}

		Sqrt square{1, x};

		//////////if (cleanSqrt(x)) { //DEPRECATED: the conditions should never be met (for the simplifier this will be needed)
		//////////    std::cout << cleanSqrt(x) << '\n';
		//////////    return 0;
		//////////}



		//while (numFactors(root) > 2) { //keep going until root is prime
		for (unsigned int i = (numFactors(square.root) - 1); i > 2; --i) {
			unsigned int factor{getFactor(square.root, i)};
			if (!(square.root % factor))
				if (cleanSqrt(factor)) {
					square.root /= factor;
					square.coef *= cleanSqrt(factor);
				}
		}

		printSqrt(square);
		idleMenu(backPressed);
	}
}

void squareSimplifier()
{ //TODO: FIX INTEGER OVERFLOW
	bool backPressed{false}; //lets us break out of the inner while loops
	while (!backPressed) {
		Sqrt square{0, 0};
		write(square.coef);

		square.coef = getUnsignedInput(backPressed); //these calls originally int
		if (!square.coef)
			continue;

		square.root = getUnsignedInput(backPressed, "r:"); 
		if (!square.root)
			continue;

		//if (backPressed)
		//	break; //band aid fix, will change most likely when implementing io functions

		square = simplifySquare(square);

		printSqrt(square);
		idleMenu(backPressed);
	}
}

void factPairCalc()
{
	bool backPressed{false}; //lets us break out of the outer while loop from inside functions
	while (!backPressed) {

		unsigned int enteredNum{0};
		enteredNum = getUnsignedInput(backPressed);
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