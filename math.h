#ifndef MATH_111005112023_H
#define MATH_111005112023_H

#include <Arduino.h>

struct Fraction {
    int numerator;
    int denominator;
};

struct Sqrt {
    unsigned int coef;
    unsigned int root;
};

struct QuadraticAnswer {
    Fraction fraction;
    Sqrt squareRoot;
};

struct Quadratic {
    QuadraticAnswer posAnswer;
    QuadraticAnswer negAnswer;
};

unsigned int cleanSqrt(unsigned int root);

Sqrt simplifySquare(Sqrt square);

void printFactors(unsigned int factor, int page);

unsigned int numFactors(unsigned int factor);

unsigned int getFactor(unsigned int composite, int numFactor);

#endif //MATH_111005112023_H