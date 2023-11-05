#ifndef MAIN_175404112023_H
#define MAIN_175404112023_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

int constexpr backButton{10}; //backButton is leftmost button
int constexpr enterButton{11};
int constexpr clearButton{12};
int constexpr deleteButton{13};

const byte ROWS = 4;
const byte COLS = 4;

LiquidCrystal_I2C lcd(0x27, 16, 2);

char keys[ROWS][COLS] = {
{'1', '2', '3', '/'},
{'4', '5', '6', '*'},
{'7', '8', '9', '-'},
{'_', '0', '.', '+'} //underscore represents negative instead of subtraction, and will still print out '-'
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#endif //MAIN_175404112023_H