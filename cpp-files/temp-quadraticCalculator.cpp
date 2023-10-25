#include <iostream>

struct fraction {
    int numerator;
    int denominator;
};

fraction simplifyFraction(fraction fraction);

int main()
{
    fraction fract1{2, 4};
    fraction result{simplifyFraction(fract1)};
    std::cout << result.numerator << '/' << result.denominator << '\n';

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
    //check if denom cleanly divides into numer
    //if so divide then return over 1
    if (!(fraction.numerator % fraction.denominator)) {
        fraction.numerator /= fraction.denominator;
        fraction.denominator = 1;
    }

    bool divisionHappened{true};
    while (divisionHappened) {
        divisionHappened = false;

        for (int i = 1; (i <= fraction.numerator) ||  (i <= fraction.denominator); ++i) {
            if (!(fraction.numerator / i) && !(fraction.denominator / i)) {
                fraction.numerator /= i;
                fraction.denominator /= i;
                divisionHappened = true;
            }
        }


    }

    //check if they can both divide by every number until the number is bigger then ![half of either of them] both of them?
    //if so divide them by that number, then keep going through until no division happens
    //while (divisionHappened)
        //divisionHappened = false;



    return fraction;
}