#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "io.h"
#include "main.h"
#include "math.h"

//TODO: use factor pair struct
void printFactors(unsigned factor, int page)
{ //max number we would need to display is 5 digits(65535), so we split the space up in groups of 5
    page *= 6; //so we only have to increase page by one in the logic above
    lcd.clear();

    for (int i = 0; i < 6; ++i) {
        lcd.setCursor((i / 2 * 5), (i % 2));
        if (getFactor(factor, (page + i)))
            lcd.print(getFactor(factor, (page + i)));
    }
}

int numFactors(unsigned int factor)
{
    int amountFactors{0};
    for (unsigned int i = 1; (i <= (factor / 2)) && (i <= (factor / i)); ++i) {
        if (!(factor % i)) {
            amountFactors += 2;
        }
    }
    return amountFactors;
}

unsigned int getFactor(unsigned int composite, int numFactor)
{
    int currentFactor{-1}; //causes the first valid factor to set it to zero, so we can start from 0 instead of 1
    for (unsigned int i = 1; (i <= (composite / 2)) && (i <= (composite / i)); ++i) {
        if (!(composite % i)) {
            if (++currentFactor == numFactor) //i is the smaller factor
                return i;
            else if (++currentFactor == numFactor)
                return (composite / i);
        }
    }
    return 0;
}