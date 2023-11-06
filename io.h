#ifndef IO_201604112023_H
#define IO_201604112023_H

#include <Arduino.h>
#include "main.h"

//prints to the lcd
void write(String topText, String bottomText = "");
void write(unsigned int topText);
void write(unsigned int arg0, char arg1, unsigned int arg2);
void write(char arg0, unsigned int arg1);

//returns a bool if there is input on a given pin, and handles debouncing
bool input(int button);

//returns the pin number of any activated pin
int isInput();

//waits for input on up to 4 pins, and handles debouncing
void waitForButton(int button0, int button1 = 0, int button2 = 0, int button3 = 0);

void idleMenu(bool& backPressed);

//checks to see if adding pressedkey to enterednum would overflow 16 bits(unsigned)
//int validateNumInput(char pressedKey, unsigned int enteredNum, String prefixString = "");
template <typename T>
T validateNumInput(char pressedKey, T enteredNum, String prefixString = "")
{
	int pressedNum = (pressedKey - '0');
	if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredNum && !pressedNum)) {
		if (enteredNum > ((((enteredNum >= 0 && ~enteredNum >= 0) ? 65535 : 32767) - pressedNum) / 10)) { //arduino is weird with ints more then 16 bit, so don't allow them
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
template <typename T>
T getNumInput(bool& backPressed, String prefixString = "")
{
	T enteredNum{0};
	write(prefixString + enteredNum);
	while (!backPressed) {

		char pressedKey = keypad.getKey();
		enteredNum = validateNumInput(pressedKey, enteredNum, prefixString);

		if (pressedKey)
			delay(50); //debounce delay

		switch (isInput()) {
		case backButton:
			backPressed = true;
			break; //would return 0 but that might break something
		case enterButton:
			if (enteredNum) {
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

#endif //IO_201604112023_H