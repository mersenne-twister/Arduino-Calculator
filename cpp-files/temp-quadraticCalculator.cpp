#include <iostream>

struct fraction {
    int numerator;
    int denominator;
};

int main()
{

    //a can't be zero

    //get a, b, c
    //root = b^2 - 4ac
    //simplify root
    //denominator = 2a
    //numerator = -b

    //2 parts:
    //(numerator + root) / denominator
    //(numerator - root) / denominator
    //simplify each fraction

}

fraction simplifyFraction(fraction fraction)
{
    if (!(fraction.numerator % fraction.denominator)) {
        fraction.numerator = (fraction.numerator / fraction.denominator);
        fraction.denominator = 1;
    }

    bool divisionHappened{true};
    while (divisionHappened) {
        divisionHappened = false;

        for (int i = 0; (i <= fraction.numerator) ||  (i <= fraction.denominator); ++i) {
            
        }


    }
    //check if denom cleanly divides into numer
    //if so divide then return over 1

    //check if they can both divide by every number until the number is bigger then ![half of either of them] both of them?
    //if so divide them by that number, then keep going through until no division happens
    //while (divisionHappened)
        //divisionHappened = false;



    return fraction;
}