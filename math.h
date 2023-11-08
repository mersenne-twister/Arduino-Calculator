#ifndef MATH_111005112023_H
#define MATH_111005112023_H

#include <Arduino.h>

struct Fraction {
    int numerator;
    int denominator;
};

struct Square {
    unsigned int coef;
    unsigned int root;
};

struct QuadraticAnswer {
    Fraction fraction;
    Square squareRoot;
};

struct Quadratic {
    QuadraticAnswer posAnswer;
    QuadraticAnswer negAnswer;
};

unsigned int cleanSqrt(unsigned int root);

Square simplifySquare(Square square);

void printFactors(unsigned int factor, int page);

unsigned int numFactors(unsigned int factor);

unsigned int getFactor(unsigned int composite, int numFactor);

#endif //MATH_111005112023_H