#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include "main.h"
#include "mainMenu.h"

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
    mainMenu(); //TODO: move main menu stuff into void loop

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