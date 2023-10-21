#include <cstdint>
#include <iostream>
#include "temp-factorCalculator.h"

std::int64_t cleanSqrt(int num);

//no input validation, this is a test
int main()
{
    //don't allow user to enter number that is too big
    //account for errors
    //don't allow negatives
    //choose to find c or b(on arduino done by pressing enter on b)
    std::cout << "A: ";
    std::int64_t a{}; //64 bit int
    std::cin >> a;
    a = (a * a);

    std::cout << "B: ";
    std::int64_t b{};
    std::cin >> b; //-27 is the temp value for not entering anything
    b = (b * b);

    std::int64_t c{};
    std::int64_t x{};
    bool findB{false};
    if (b == (-27 * -27)) {
        findB = true;
        std::cout << "C: ";
        std::cin >> c;
        c = (c * c);
        x = (c - a);
    } else
        x = (a + b);
    
    if (cleanSqrt(x)) {
        std::cout << cleanSqrt(x) << '\n';
        return 0;
    }

    

    //check if any of the factors of x are squares
    //modify factor function to find number of factors,
    //and then be able to get a given factor based off their number

    //make sure we have the biggest rootable factor
    //if so then subtract them from x print them before x

    //if not then just print x

    return 0;
}

//returns sqrt, or 0 if it can't cleanly be rooted
std::int64_t cleanSqrt(int num)
{
    for (int i = 1; i*i <= num; ++i) {
        if ((i * i) == num)
            return i;
    }
    return 0;
}

//returns the sqrt, with up to [8?(for the lcd screen)] digits of precision
double decSqrt(int num)
{
    return 0.0;
}