#ifndef IO_201604112023_H
#define IO_201604112023_H

#include <Arduino.h>

//prints to the lcd
void write(String topText, String bottomText = "");
void write(unsigned int topText);

//returns a bool if there is input on a given pin, and handles debouncing
bool input(int button);

//returns the pin number of any activated pin
int isInput();

//waits for input on up to 4 pins, and handles debouncing
void waitForButton(int button0, int button1 = 0, int button2 = 0, int button3 = 0);

//checks to see if adding pressedkey to enterednum would overflow 16 bits(unsigned)
int validateNumInput(char pressedKey, unsigned int enteredNum);

//gets unsigned integer input
int getNumInput(bool& backPressed);

#endif //IO_201604112023_H