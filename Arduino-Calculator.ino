#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

LiquidCrystal_I2C lcd(0x27, 16, 2);

char keys[ROWS][COLS] = {
{'1', '2', '3', '/'},
{'4', '5', '6', '*'},
{'7', '8', '9', '-'},
{'-', '0', '.', '+'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.clear();
  lcd.backlight();

  // lcd.setCursor(2, 0);
  // lcd.print("Hallo World!");
  // lcd.setCursor(1, 1);
  // lcd.print("ROCK 'N' ROLL");
}

void loop() {
  char pressedKey = keypad.getKey();

  if (pressedKey)
    lcd.print(pressedKey);
}
