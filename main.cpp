#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "main.h"
#include "io.h"

byte constexpr ROWS{4};
byte constexpr COLS{4};

char constexpr keys[ROWS][COLS]{
{'1', '2', '3', '/'},
{'4', '5', '6', '*'},
{'7', '8', '9', '-'},
{'_', '0', '.', '+'} //underscore represents negative instead of subtraction, and will still print out '-'
};

byte rowPins[ROWS]{9, 8, 7, 6};
byte colPins[COLS]{5, 4, 3, 2};

Keypad keypad{Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS)};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(backButton, INPUT);
    pinMode(enterButton, INPUT);
    pinMode(clearButton, INPUT);
    pinMode(deleteButton, INPUT);

    Serial.begin(9600);
  
    lcd.init();
    lcd.clear();
    lcd.backlight();
}

void loop() {
	String const menus[16] = { //this would be constexpr but apparently arduino strings can't be
	"Exact Arithmetic", "   Calculator", //leading spaces for center allignment
	" Dec Arithmetic", "   Calculator",
	"  Factor Pair", "   Calculator",
	"  Square Root", "   Simplifier",
	"  Square Root", "   Calculator",
	"    Fraction", "   Simplifier",
	"Pythagorean Theo", "   Calculator",
	//hook up the root calcs
	" Quadratic Form", "   Calculator",
	//hook up root calc
	};

	int currentMenu{0};
	write(menus[currentMenu], menus[currentMenu + 1]);
	while (true) {
		bool buttonPressed{false};
		while (!buttonPressed) {
			if (digitalRead(enterButton)) {
				delay(50);
				while (digitalRead(enterButton));

				switch (currentMenu) {
				case 0:
					//ex arithmetic calc
				case 2:
					//dec arithmetic calc
				case 4:
					//factor pair calc
				case 6:
					//sqrt simpl
				case 8:
					//sqrt calc
				case 10:
					//fract simpl
				case 12:
					//pyth theo calc
				case 14:
					//quad form calc
				default:
					lcd.clear();
					lcd.print("ERROR BAD MENU");
					while (true);
				}

				write(menus[currentMenu], menus[currentMenu + 1]);
			}

			if (digitalRead(deleteButton)) {
				buttonPressed = true;
				delay(50); //debounce delay

				currentMenu += 2;

				if (currentMenu > 12)
					currentMenu = 0;

				write(menus[currentMenu], menus[currentMenu + 1]);
				while (digitalRead(deleteButton)); //wait until they lift the button up
				delay(50);
			}

			if (digitalRead(clearButton)) {
				buttonPressed = true;
				delay(50); //debounce delay

				currentMenu -= 2;

				if (currentMenu < 0)
					currentMenu = 12;

				write(menus[currentMenu], menus[currentMenu + 1]);
				while (digitalRead(clearButton)); //wait until they lift the button up
				delay(50);
			}
		}




	}

	//select if enter
	//cycle if delete

    //TODO: divide by zero thought you were slick didn't ya shutting downc:\Users\Jamie\source\repos\tests\Arduino-Calculator\Arduino-Calculator.ino
    //divide by zero unlocks secret mode??


}

//TODO: switch while loops to semicolon

//likely won't use this
////enter the expression to assert, and the same expression in quotes so we can find the assertion
//void assert(bool isValid, String assertion)
//{
//    if (!isValid) {
//        lcd.clear();
//        lcd.print("   ASSERTION");
//        lcd.setCursor(0, 1);
//        lcd.print("     ERROR");
//        Serial.print("ASSERTION ERROR: ");
//        Serial.println(assertion);
//    }
//}