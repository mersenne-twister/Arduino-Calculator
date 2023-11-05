#include <Arduino.h>
#include "main.h"
#include "mainMenu.h"

//TODO: move this inside mainMenu
String const menus[14] = { //this would be constexpr but apparently arduino strings can't be
	"   Arithmetic", "   Calculator", //leading spaces for center allignment
	//exact calculator
	//decimal
	"  Factor Pair", "   Calculator",
	"  Square Root", "   Simplifier",
	//exact
	//decimal
	"    Fraction", "   Simplifier",
	//exact
	"Pythagorean Theo", "   Calculator",
	//hook up the root calcs
	" Quadratic Form", "   Calculator",
	//hook up root calc
	"Knuth's Up Arrow", "Notat Calculator" //DEPRECATED
};

void mainMenu()
{
	int currentMenu{0};
	writeMenu(currentMenu);
	while (true) {
		bool buttonPressed{false};
		while (!buttonPressed) {
			if (digitalRead(enterButton)) {
				delay(50);
				while (digitalRead(enterButton));

				switch (currentMenu) {
				case 0:
					lcd.clear();
					lcd.print("1 + 1 = 2");//temp
					break;
				case 2:
					//factPairCalculator();
					break;
				case 4:
					//squareSimplifier();
					break;
				case 6:

				case 8:

				case 10:
				case 12:

				default:
					lcd.clear();
					lcd.print("ERROR BAD MENU");
					while (true);
				}

				writeMenu(currentMenu);
			}

			if (digitalRead(deleteButton)) {
				buttonPressed = true;
				delay(50); //debounce delay

				currentMenu += 2;

				if (currentMenu > 12)
					currentMenu = 0;

				writeMenu(currentMenu);
				while (digitalRead(deleteButton)); //wait until they lift the button up
				delay(50);
			}

			if (digitalRead(clearButton)) {
				buttonPressed = true;
				delay(50); //debounce delay

				currentMenu -= 2;

				if (currentMenu < 0)
					currentMenu = 12;

				writeMenu(currentMenu);
				while (digitalRead(clearButton)); //wait until they lift the button up
				delay(50);
			}
		}




	}

	//select if enter
	//cycle if delete



}

//TODO: update to use print instead of this
void writeMenu(int currentMenu)
{
	lcd.clear();
	lcd.print(menus[currentMenu]);
	lcd.setCursor(0, 1); //display the bottom half
	lcd.print(menus[currentMenu + 1]);
}