void mainMenu()
{
  String const menus[8] = {
    "   Arithmetic", "   Calculator", //leading spaces for center allignment
    "  Factor Pair", "   Calculator",
    "Pythagorean theo", "   Calculator",
    " Quadratic Form", "   Calculator",
    "Knuth's Up Arrow", "Notat Calculator"
  };

  int currentMenu{0};

  while (true) {
    lcd.clear();
    lcd.print(menus[currentMenu]);
    lcd.setCursor(0, 1); //display the bottom half
    lcd.print(menus[currentMenu += 1]);

    bool buttonPressed{false};
    while (!buttonPressed) {
      if (digitalRead(enterButton)) {
        delay(50);

        switch (currentMenu) {
        case 0:

        case 2:

        case 4:

        case 6:

        case 8:
        
        case 10:
        default:
          lcd.clear();
          lcd.print("ERROR BAD MENU");
          while (true) {}
          break; //wont' trigger, but break for posterity
        }
      }

      if (digitalRead(deleteButton)) {
        delay(50); //debounce delay
        
        currentMenu += 2;
        if (currentMenu > 10)
        currentMenu = 0;
        buttonPressed = true;
      }
    }




  }

  //select if enter
  //cycle if delete



}