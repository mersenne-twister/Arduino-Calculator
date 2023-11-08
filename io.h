#ifndef IO_201604112023_H
#define IO_201604112023_H

#include <Arduino.h>
#include "main.h"
#include "math.h"

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

void printSqrt(Sqrt sqrt);

void idleMenu(bool& backPressed);

unsigned int validateUnsignedInput(char pressedKey, unsigned int enteredNum, String prefixString = "",
								   unsigned int maxInput = 65535);

unsigned int getUnsignedInput(bool& backPressed, String prefixString = "", unsigned int minInput = 1,
							  unsigned int maxInput = 65535);

//checks to see if adding pressedkey to enterednum would overflow 16 bits(unsigned)
//int validateNumInput(char pressedKey, unsigned int enteredNum, String prefixString = "");


#endif //IO_201604112023_H