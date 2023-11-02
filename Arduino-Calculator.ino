#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

int constexpr backButton{  10}; //backButton is leftmost button
int constexpr enterButton{ 11};
int constexpr clearButton{ 12};
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

void setup() {
  pinMode(backButton, INPUT);
  pinMode(enterButton, INPUT);
  pinMode(clearButton, INPUT);
  pinMode(deleteButton, INPUT);


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
  mainMenu(); //TODO: move main menu stuff into void loop

  //TODO: divide by zero thought you were slick didn't ya shutting down
  //divide by zero unlocks secret mode??





  // if (digitalRead(backButton)) {
  //   lcd.setCursor(0, 0);
  //   lcd.print("1");
  //   Serial.println("back on");
  // } else {
  //   lcd.setCursor(0, 0);
  //   lcd.print(" ");
  // }

  // if (digitalRead(enterButton)) {
  //   lcd.setCursor(1, 0);
  //   lcd.print("2");
  //   Serial.println("enter on");
  // } else {
  //   lcd.setCursor(1, 0);
  //   lcd.print(" ");
  // }

  // if (digitalRead(clearButton)) {
  //   lcd.setCursor(2, 0);
  //   lcd.print("3");
  //   Serial.println("clear on");
  // } else {
  //   lcd.setCursor(2, 0);
  //   lcd.print(" ");
  // }

  // if (digitalRead(deleteButton)) {
  //   lcd.setCursor(3, 0);
  //   lcd.print("4");
  //   Serial.println("delete on");
  // } else {
  //   lcd.setCursor(3, 0);
  //   lcd.print(" ");
  // }

  //delay(50);
  // char pressedKey = keypad.getKey();

  // if (pressedKey)
  //   lcd.print(pressedKey);
}

//enter the expression to assert, and the same expression in quotes so we can find the assertion
void assert(bool isValid, String assertion)
{
  if (!isValid) {
    lcd.clear();
    lcd.print("   ASSERTION");
    lcd.setcursor(0, 1);
    lcd.print("     ERROR");
    Serial.print("ASSERTION ERROR: ");
    Serial.println(assertion);
  }
}