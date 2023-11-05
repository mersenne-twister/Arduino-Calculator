#ifndef MAIN_175404112023_H
#define MAIN_175404112023_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

int constexpr backButton{10}; //backButton is leftmost button
int constexpr enterButton{11};
int constexpr clearButton{12};
int constexpr deleteButton{13};

//forward declaration for lcd because the odr rule hates me with a passion
extern LiquidCrystal_I2C lcd;

extern Keypad keypad;

#endif //MAIN_175404112023_H