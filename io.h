#ifndef IO_201604112023_H
#define IO_201604112023_H

#include <Arduino.h>

//prints to the lcd
void print(String topText, String bottomText = "");

//returns a bool if there is input on a given pin, and handles debouncing
bool input(int button);

//waits for input on up to 4 pins, and handles debouncing
void waitForButton(int button);

//checks to see if adding pressedkey to enterednum would overflow 16 bits(unsigned)
int validateNumInput(int pressedKey, int enteredNum);

//gets unsigned integer input
int getNumInput(bool& backPressed);

#endif //IO_201604112023_H