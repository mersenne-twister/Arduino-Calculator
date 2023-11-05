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
	while (!input(button0) || !input(button1) || !input(button2) || !input(button3));
}

int validateNumInput(char pressedKey, unsigned int enteredNum)
{
	int pressedNum = (pressedKey - '0');
	if ((pressedNum >= 0) && (pressedNum <= 9) && !(!enteredNum && !pressedNum)) {
		if (enteredNum > ((65535 - pressedNum) / 10)) { //arduino is weird with ints more then 16 bit, so don't allow them
			write("Max num size");
			waitForButton(enterButton);
		} else {
			enteredNum = (enteredNum * 10) + pressedNum;
		}
		write(enteredNum);
	}

	return enteredNum;
}

int getNumInput(bool& backPressed)
{
	unsigned int enteredNum{0};
	write(enteredNum);
	while (!backPressed) {

		char pressedKey = keypad.getKey();
		enteredNum = validateNumInput(pressedKey, enteredNum);

		if (pressedKey)
			delay(50); //debounce delay

		switch (isInput()) {
		case backButton:
			backPressed = true;
			return 1; //would return 0 but that might break something
		case enterButton:
			if (enteredNum) {
				return enteredNum;
			} else {
				write("Must enter", "number");
				waitForButton(enterButton);
				write(enteredNum);
			}
			break;
		case clearButton:
			enteredNum = 0;
			write(enteredNum);
			break;
		case deleteButton:
			enteredNum /= 10;
			write(enteredNum);
			break;
		default:
			break;
		}
	}
}