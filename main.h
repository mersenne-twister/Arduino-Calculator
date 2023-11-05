#ifndef MAIN_175404112023_H
#define MAIN_175404112023_H

#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

int constexpr backButton{10}; //backButton is leftmost button
int constexpr enterButton{11};
int constexpr clearButton{12};
int constexpr deleteButton{13};

extern LiquidCrystal_I2C lcd;

#endif //MAIN_175404112023_H