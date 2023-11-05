#ifndef IO_201604112023_H
#define IO_201604112023_H

#include <Arduino.h>

void print(String topText, String bottomText = "");

bool input(int button);

void waitForButton(int button);

int validateNumInput(int pressedKey, int enteredNum);

int getNumInput(bool& backPressed);

#endif //IO_201604112023_H