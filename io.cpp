#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "main.h"

//TOOD: replace all lcd interaction with this function
void write(String topText, String bottomText = "")
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

//TODO: replace all input with this function
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

void waitForButton(int button0, int button1 = 0, int button2 = 0, int button3 = 0)
{
	while (!(input(button0) || input(button1) || input(button2) || input(button3)));
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