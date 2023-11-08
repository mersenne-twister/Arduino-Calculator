#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "main.h"
#include "math.h"
#include "io.h"

//TOOD: replace all lcd interaction with this function
void write(String topText, String bottomText)
{
	lcd.clear();
	lcd.print(topText);
	lcd.setCursor(0, 1);
	lcd.print(bottomText);
}

void write(unsigned int topText)
{
	lcd.clear();
	lcd.print(topText);
}

void write(unsigned int arg0, char arg1, unsigned int arg2)
{
	lcd.clear();
	lcd.print(arg0);
	lcd.print(arg1);
	lcd.print(arg2);
}

void write(char arg0, unsigned int arg1)
{
	lcd.clear();
	lcd.print(arg0);
	lcd.print(arg1);
}

bool input(int button)
{
	if ((button < 2) || (button > 13) || !digitalRead(button))
		return false;

	delay(50);
	while (digitalRead(button));
	delay(50);
	return true;
}

int isInput()
{
	if (input(backButton))
		return backButton;
	else if (input(enterButton))
		return enterButton;
	else if (input(clearButton))
		return clearButton;
	else if (input(deleteButton))
		return deleteButton;
	return 0;
}

void waitForButton(int button0, int button1, int button2, int button3)
{
	while (!(input(button0) || input(button1) || input(button2) || input(button3)));
}

void printSqrt(Sqrt sqrt)
{ //CONSIDER: use direct lcd interaction to facilitate incorporation with the quadformcalc?		
	if (sqrt.root == 1) //TODO: restructure this so that we only have one print for each given thing
		write(sqrt.coef);
	else if (sqrt.coef == 1)
		write('r', sqrt.root);
	else
		write(sqrt.coef, 'r', sqrt.root);
}

void idleMenu(bool& backPressed)
{
	while (!backPressed) {
		switch (isInput()) {
		case backButton:
			backPressed = true;
			break;
		case enterButton:
		case clearButton:
			return;
		case deleteButton:
		default:
			break;
		}
	}
}

unsigned int validateUnsignedInput(char pressedKey, unsigned int enteredNum, String prefixString,
								   unsigned int maxInput)
{
	int pressedNum = (pressedKey - '0');
	if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredNum && !pressedNum)) {
		if (enteredNum > ((maxInput - pressedNum) / 10)) {
			write("Max num size");
			waitForButton(enterButton);
		} else {
			enteredNum = (enteredNum * 10) + pressedNum;
		}
		write(prefixString + enteredNum);
	}

	return enteredNum;
}

//gets integer input, signed or unsigned
//unsigned int getNumInput(bool& backPressed, String prefixString = "");
unsigned int getUnsignedInput(bool& backPressed, String prefixString, unsigned int minInput,
							  unsigned int maxInput)
{
	unsigned int enteredNum{0};
	write(prefixString + enteredNum);
	while (!backPressed) {

		char pressedKey = keypad.getKey();
		enteredNum = validateUnsignedInput(pressedKey, enteredNum, prefixString, maxInput);

		if (pressedKey)
			delay(50); //debounce delay

		switch (isInput()) {
		case backButton:
			backPressed = true;
			break; //would return 0 but that might break something
		case enterButton:
			if (enteredNum >= minInput) {
				return enteredNum;
			} else {
				write("Must enter", "number");
				waitForButton(enterButton);
				write(prefixString + enteredNum);
			}
			break;
		case clearButton:
			return 0;
		case deleteButton:
			enteredNum /= 10;
			write(prefixString + enteredNum);
			break;
		default:
			break;
		}
	}
	//only triggers if back is pressed
	return 1; //would return 0 but that might break something
}