#include <iostream>

//no input validation, this is a test
int main()
{
    //don't allow user to enter number that is too big
    //account for errors
    //don't allow negatives
    //choose to find c or b(on arduino done by pressing enter on b)
    std::cout << "A: ";
    int64_t a{}; //64 bit int
    std::cin >> a;
    a = (a * a);

    std::cout << "B: ";
    int64_t b{};
    std::cin >> b; //-27 is the temp value for not entering anything
    b = (b * b);

    int64_t c{};
    int64_t x{};
    bool findB{false};
    if (b == (-27 * -27)) {
        findB = true;
        std::cout << "C: ";
        std::cin >> c;
        c = (c * c);
        x = (c - a);
    } else
        x = (a + b);
    
    //check if x is a square
    //if so, root it
    //check if any of the factors of x are squares
    //modify factor function to find number of factors,
    //and then be able to get a given factor based off their number

    //make sure we have the biggest rootable factor
    //if so then subtract them from x print them before x

    //if not then just print x
}