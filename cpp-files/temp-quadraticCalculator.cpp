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

struct Quadratic {
    QuadraticAnswer posAnswer;
    QuadraticAnswer negAnswer;
};

//these are for indicating an error
Fraction const nullFraction{-1, -1};
SquareRoot const nullSquareRoot{-1, -1};
QuadraticAnswer const nullQuadraticAnswer{nullFraction, nullSquareRoot};
Quadratic const nullQuadratic{nullQuadraticAnswer, nullQuadraticAnswer};

Fraction simplifyFraction(Fraction fraction);

Quadratic quadraticSimplifier(int a, int b, int c);

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

    Quadratic quadratic{quadraticSimplifier(a, b, c)};
    
    std::cout << quadratic.posAnswer.fraction.numerator << '/' << quadratic.posAnswer.fraction.denominator
    << quadratic.negAnswer.fraction.numerator << '/' << quadratic.negAnswer.fraction.denominator << '\n';
}

//quadratic simplifier
Quadratic quadraticSimplifier(int a, int b, int c)
{
    QuadraticAnswer answer{};
    answer.squareRoot.root = (b * b) - (4 * a * c);

    if (answer.squareRoot.root < 0) {
        std::cout << "unsolvable.\n";
        return nullQuadratic;
    }
    answer.squareRoot.coefficient = 1;

    
    // //TODO: MAKE THIS INTO A FUNCTION
    // for (int i = (numFactors(root) - 1); i > 2; --i) {
    //     int factor{getFactor(root, i)};


    answer.fraction.numerator = -b;
    answer.fraction.denominator = (2 * a);
    
    QuadraticAnswer posAnswer;
    QuadraticAnswer negAnswer;

    //for the time being, we're assuming we can always get the root
    if (cleanSqrt(answer.squareRoot.root) != -1) { //triggers if we can simplify the root
        posAnswer.fraction.numerator = answer.fraction.numerator + cleanSqrt(answer.squareRoot.root);
        negAnswer.fraction.numerator = answer.fraction.numerator - cleanSqrt(answer.squareRoot.root);

        //tells main to only print the fraction
        //TODO: replace with a const(expr?) Fraction struct
        posAnswer.squareRoot.coefficient = -1;
        posAnswer.squareRoot.root = -1;
        negAnswer.squareRoot.coefficient = -1;
        negAnswer.squareRoot.root = -1;

        posAnswer.fraction = simplifyFraction(posAnswer.fraction);
        negAnswer.fraction = simplifyFraction(negAnswer.fraction);

        Quadratic quadratic{posAnswer, negAnswer};
        return quadratic;
    } else {
        std::cout << "cannot simplify root.\n";
        return nullQuadratic; //TODO: add support for unsimplifiable answers
    }
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
