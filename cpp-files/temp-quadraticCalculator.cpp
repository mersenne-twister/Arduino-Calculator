#include <iostream>
#include "temp-factorCalculator.h"

struct Fraction {
    int numerator;
    int denominator;
};

struct Square {
    int coefficient;
    int root;
};

struct QuadraticAnswer {
    Fraction fraction;
    Square squareRoot;
};

struct Quadratic {
    QuadraticAnswer posAnswer;
    QuadraticAnswer negAnswer;
};

//these are for indicating an error
//TODO: replace with constexpr?
Fraction const nullFraction{-1, -1};
Square const nullSquareRoot{-1, -1};
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
    
    //printing cases:
        //fraction only
            //if they're identical, just print once
                //non-whole
                    //x = num/denom = mixednum
                //whole(denom is 1)
                    //x = num
        //denom is 1(with root)
            //print num +- coef(root)
        //denom isn't 1
            //print (num +- coef(root) / denom)
    //i?????????
    std::cout << "x = " << quadratic.posAnswer.fraction.numerator << '/' << quadratic.posAnswer.fraction.denominator
    << ", x = " << quadratic.negAnswer.fraction.numerator << '/' << quadratic.negAnswer.fraction.denominator << '\n';
}

//quadratic simplifier
Quadratic quadraticSimplifier(int a, int b, int c)
{
    QuadraticAnswer answer{};
    answer.squareRoot.root = (b * b) - (4 * a * c);

    answer.squareRoot.coefficient = 1;

    answer.fraction.numerator = -b;
    answer.fraction.denominator = (2 * a);
    
    if (answer.squareRoot.root < 0) { //TODO: handle negative root
        std::cout << "unsolvable.\n";
        return nullQuadratic;
    }

    QuadraticAnswer posAnswer;
    QuadraticAnswer negAnswer;

    posAnswer.fraction = negAnswer.fraction = answer.fraction;

    //TODO: moe as much code as possible out of the if/else

    //for the time being, we're assuming we can always get the root
    if (cleanSqrt(answer.squareRoot.root) != -1) { //triggers if we can simplify the root
        posAnswer.fraction.numerator = answer.fraction.numerator + cleanSqrt(answer.squareRoot.root);
        negAnswer.fraction.numerator = answer.fraction.numerator - cleanSqrt(answer.squareRoot.root);

        //tells outer function to only print the fraction
        //TODO: replace with 1 or 0 root(0)
        posAnswer.squareRoot = negAnswer.squareRoot = nullSquareRoot;

        posAnswer.fraction = simplifyFraction(posAnswer.fraction);
        negAnswer.fraction = simplifyFraction(negAnswer.fraction);

        Quadratic quadratic{posAnswer, negAnswer};
        return quadratic;
    } else {
        //cases:
            //simplify fraction
            //simplify root



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
    return fraction;
}

int cleanSqrt(int num)
{
    //add a while loop?
    if (!num)
        return num;
    
    for (int i = 1; i*i <= num; ++i) {
        if ((i * i) == num)
            return i;
    }
    return -1;
}

Square simplifySquare(Square square)
{
    if (cleanSqrt(square.root)) { //logic to simplify expression
      square.coefficient *= cleanSqrt(square.root);
      square.root = 1;
    } else {
      for (int i = (numFactors(square.root) - 1); i > 2; --i) {
          int factor{getFactor(square.root, (i))};

          if (!(enteredRoot % factor))
              if (cleanSqrt(factor)) {
                  enteredRoot /= factor;
                  enteredCof *= cleanSqrt(factor);
              }
      }
    }
}