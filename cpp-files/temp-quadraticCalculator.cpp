#include <iostream>
#include "temp-factorCalculator.h"

struct Fraction {
    int numerator;
    int denominator;
};

struct SquareRoot {
    int coefficient;
    int root;
};

struct QuadraticAnswer {
    Fraction fraction;
    SquareRoot squareRoot;
};

Fraction simplifyFraction(Fraction fraction);

int cleanSqrt(int num);

//TODO: MAKE INO FILE FOR GENERAL MATH FUNCTIONS
int main()
{
    std::cout << "a: ";
    int a{};
    std::cin >> a;
    if (!a) {
        std::cout << "'a' must be nonzero\n";
        return 0;
    }

    std::cout << "b: ";
    int b{};
    std::cin >> b;

    std::cout << "c: ";
    int c{};
    std::cin >> c;

    //get a, b, c
    //root = b^2 - 4ac
    //simplify root
    //denominator = 2a
    //numerator = -b

    //TODO: MAKE STRUCT FOR ROOT AND COEFFICIENT
    QuadraticAnswer answer{};
    answer.squareRoot.root = (b * b) - (4 * a * c);

    //int root{(b * b) - (4 * a * c)};
    if (answer.squareRoot.root < 0) {
        std::cout << "unsolvable.\n";
        return 0;
    }
    answer.squareRoot.coefficient = 1;

    //this is being moved closer to the other logic for now
    // if (cleanSqrt(root)) {
    //     coefficient = cleanSqrt(root);
    //     root = 1;
    // }

    //for the time being, we're assuming we can always get the root of `root`
    // //TODO: MAKE THIS INTO A FUNCTION
    // for (int i = (numFactors(root) - 1); i > 2; --i) {
    //     int factor{getFactor(root, i)};

    //     if (!(root % factor))
    //         if (cleanSqrt(factor)) {
    //             root /= factor;
    //             coefficient *= cleanSqrt(factor);
    //         }
    // }

    //int numerator{-b};
    answer.fraction.numerator = -b;
    //int denominator{2 * a};
    answer.fraction.denominator = (2 * a);
    
    QuadraticAnswer posAnswer;
    QuadraticAnswer negAnswer;

    if (cleanSqrt(answer.squareRoot.root) != -1) {
        posAnswer.fraction.numerator = answer.fraction.numerator + cleanSqrt(answer.squareRoot.root);
        negAnswer.fraction.numerator = answer.fraction.numerator - cleanSqrt(answer.squareRoot.root);
    } else {
        std::cout << "cannot simplify root.\n";
        return 0; //TODO: add support for unsimplifiable answers
    }
    
    //Fraction posanswer{(numerator + root), denominator};
    //posanswer = simplifyFraction(posanswer);
    posAnswer.fraction = simplifyFraction(posAnswer.fraction);

    //Fraction neganswer{(numerator - root), denominator};
    //neganswer = simplifyFraction(neganswer);

    std::cout << "x = " << posanswer.fraction.numerator << '/' << posanswer.denominator
    << ", " << "x = " << neganswer.fraction.numerator << '/' << neganswer.denominator << '\n';

    //2 parts:
    //(numerator + root) / denominator
    //(numerator - root) / denominator
    //simplify each fraction

}

Fraction simplifyFraction(Fraction fraction)
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

        for (int i = 2; (i <= fraction.numerator) ||  (i <= fraction.denominator); ++i) {
            if (!(fraction.numerator % i) && !(fraction.denominator % i)) {
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

int cleanSqrt(int num)
{
    if (!num)
        return num;
    
    for (int i = 1; i*i <= num; ++i) {
        if ((i * i) == num)
            return i;
    }
    return -1;
}
