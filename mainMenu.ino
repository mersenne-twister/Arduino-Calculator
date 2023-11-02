String const menus[14] = { //this would be constexpr but apparently arduino strings can't be
    "   Arithmetic", "   Calculator", //leading spaces for center allignment
    "  Factor Pair", "   Calculator",
    "  Square Root", "   Simplifier",
    "    Fraction", "   Simplifier",
    "Pythagorean Theo", "   Calculator",
    " Quadratic Form", "   Calculator",
    //square root dec calc
    //fraction dec calc
    //
    "Knuth's Up Arrow", "Notat Calculator"
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
        while (digitalRead(enterButton)) {}

        switch (currentMenu) {
        case 0:
          lcd.clear();
          lcd.print("1 + 1 = 2");//temp
          break;
        case 2:
          factPairCalculator();
          break;
        case 4:
          squareSimplifier();
          break;
        case 6:

        case 8:
        
        case 10:
          quadCalc();
        case 12:

        default:
          lcd.clear();
          lcd.print("ERROR BAD MENU");
          while (true) {}
          break; //wont' trigger, but break for posterity
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
        while (digitalRead(deleteButton)) {} //wait until they lift the button up
        delay(50);
      }

      if (digitalRead(clearButton)) {
        buttonPressed = true;
        delay(50); //debounce delay

        currentMenu -= 2;
        
        if (currentMenu < 0)
        currentMenu = 12;

        writeMenu(currentMenu);
        while (digitalRead(clearButton)) {} //wait until they lift the button up
        delay(50);
      }
    }




  }

  //select if enter
  //cycle if delete



}

//writes the current menu to the lcd
void writeMenu(int currentMenu)
{
  lcd.clear();
  lcd.print(menus[currentMenu]);
  lcd.setCursor(0, 1); //display the bottom half
  lcd.print(menus[currentMenu + 1]);
}