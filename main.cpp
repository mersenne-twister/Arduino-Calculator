#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "main.h"
#include "calculators.h"
#include "io.h"

byte constexpr ROWS{4};
byte constexpr COLS{4};

byte rowPins[ROWS]{9, 8, 7, 6}; //byte array can't be const
byte colPins[COLS]{5, 4, 3, 2};

char constexpr keys[ROWS][COLS]{
{'1', '2', '3', '/'},
{'4', '5', '6', '*'},
{'7', '8', '9', '-'},
{'_', '0', '.', '+'} //underscore represents negative instead of subtraction, and will still print out '-'
};

Keypad keypad{Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS)};

LiquidCrystal_I2C lcd(0x27, 16, 2);

void activateCalculator(int currentMenu);

void setup()
{
	pinMode(backButton, INPUT);
	pinMode(enterButton, INPUT);
	pinMode(clearButton, INPUT);
	pinMode(deleteButton, INPUT);

	Serial.begin(9600);

	lcd.init();
	lcd.clear();
	lcd.backlight();
}

void loop()
{
	String const menus[14] = { //this would be constexpr but apparently arduino strings can't be
	"Exact Arithmetic", "   Calculator", //leading spaces for center allignment
	" Dec Arithmetic", "   Calculator",
	"  Factor Pair", "   Calculator",
	"  Square Root", "   Simplifier",
	//sqrt calc
	"    Fraction", "   Simplifier",
	"Pythagorean Theo", "   Calculator",
	//hook up the root calcs
	" Quadratic Form", "   Calculator",
	//hook up root calc
	};

	int currentMenu{0};
	write(menus[currentMenu], menus[currentMenu + 1]);
	while (true) {
		switch (isInput()) {
		case enterButton:
			activateCalculator(currentMenu);
			write(menus[currentMenu], menus[currentMenu + 1]);
			break;
		case clearButton:
			currentMenu -= 2;
			if (currentMenu < 0)
				currentMenu = 12;
			write(menus[currentMenu], menus[currentMenu + 1]);
			break;
		case deleteButton:
			currentMenu += 2;
			if (currentMenu > 12)
				currentMenu = 0;
			write(menus[currentMenu], menus[currentMenu + 1]);
			break;
		case backButton: //TODO: add use for backbutton here
		default:
			break;
		}
	}
}

void activateCalculator(int currentMenu)
{
	switch (currentMenu) {
	case 0:
		//ex arithmetic calc
		break;
	case 2:
		//dec arithmetic calc
		break;
	case 4:
		factPairCalc();
		break;
	case 6:
		sqrtSimplifier();
		break;
	case 8:
		//fract simpl
		break;
	case 10:
		pythTheoCalc();
		break;
	case 12:
		//quad form calc
		break;
	default:
		write("ERROR BAD MENU");
		while (true);
	}
}

//TODO: make sure no unnecessary funcs in headers

//TODO: divide by zero thought you were slick didn't ya shutting down
//divide by zero unlocks secret mode??