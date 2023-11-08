#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "io.h"
#include "main.h"
#include "math.h"

unsigned int cleanSqrt(unsigned int root)
{
	//add a while loop?
	if (!root)
		return root;

	for (int i = 1; i * i <= root; ++i) {
		if ((i * i) == root)
			return i;
		
	}
	return 65535; //65535 will never be the factor of a 16 bit int
}

Sqrt simplifySqrt(Sqrt sqrt)
{
	if (cleanSqrt(sqrt.root) != 65535) {
		sqrt.coef *= cleanSqrt(sqrt.root);
		sqrt.root = 1;
	} else {
		for (unsigned int i = (numFactors(sqrt.root) - 1); i > 2; --i) {
			unsigned int factor{getFactor(sqrt.root, (i))};
			if (!(sqrt.root % factor) && (cleanSqrt(factor) != 65535)) {
				sqrt.coef *= cleanSqrt(factor);
				sqrt.root /= factor;
			}
		}
	}
	return sqrt;
}

void printFactors(unsigned int factor, int page)
{ //max number we would need to display is 5 digits(65535), so we split the space up in groups of 5
	page *= 6; //so we only have to increase page by one in the logic
	lcd.clear();

	int spacing{6}; //6 leaves a space inbetween the 3 outputs, but will cut off the third num if
	if (getFactor(factor, (page + 5)) >= 10000) //it's got 5 digits
		spacing = 5;



	for (int i = 0; i < 6; ++i) {
		lcd.setCursor((i / 2 * spacing), (i % 2));
		if (getFactor(factor, (page + i)))
			lcd.print(getFactor(factor, (page + i)));
	}
}

unsigned int numFactors(unsigned int factor)
{
	int amountFactors{0};
	for (unsigned int i = 1; (i <= (factor / 2)) && (i <= (factor / i)); ++i) {
		if (!(factor % i)) {
			amountFactors += 2;
		}
	}
	return amountFactors;
}

unsigned int getFactor(unsigned int composite, int numFactor)
{
	int currentFactor{-1}; //causes the first valid factor to set it to zero, so we can start from 0 instead of 1
	for (unsigned int i = 1; (i <= (composite / 2)) && (i <= (composite / i)); ++i) {
		if (!(composite % i)) {
			if (++currentFactor == numFactor) //i is the smaller factor
				return i;
			else if (++currentFactor == numFactor)
				return (composite / i);
		}
	}
	return 0;
}