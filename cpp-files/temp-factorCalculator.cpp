#include <cstdint>
#include <iostream>

// int main()
// {
//     int inputNumber{};
//     std::cout << "Enter a number to be factored: ";
//     std::cin >> inputNumber; //TODO: input validation

//     //do fp division then use mod to check if whole

//     for (int i = 1; ((i <= (inputNumber / 2)) && (i <= (inputNumber / i))); ++i) {
//         if (!(inputNumber % i)) {
//             int factor{inputNumber / i};
//             std::cout << ((factor <= i) ? factor : i) << ", " << ((factor >= i) ? factor : i) << '\n';
//         }
//     }




//     return 0;
// }

//finds the number of factors of a number
int numFactors(int num)
{
    int factors{0};
    for (int i = 1; (i <= (num / 2)) && (i <= (num / i)); ++i) {
        if (!(num % i)) {
            factors += 2;
        }
    }
    return factors;
}

int getFactor(int composite, int numFactor)
{
    int currentFactor{-1}; //causes the first valid factor to set it to zero, so we can start from 0 instead of 1
    for (int i = 1; (i <= (composite / 2)) && (i <= (composite / i)); ++i) {
        if (!(composite % i)) {
            if (++currentFactor == numFactor) //i is the smaller factor
                return i;
            else if (++currentFactor == numFactor)
                return (composite / i);
        }
    }
    return 0;
}

//code for finding factor
//
//int inputNumber{};
//std::cout << "Enter a number to be factored: ";
//std::cin >> inputNumber; //TODO: input validation
//
////do fp division then use mod to check if whole
//
//for (int i = 1; ((i <= inputNumber / 2) && (i <= (inputNumber / i))); ++i) {
//    if (!(inputNumber % i)) {
//        int factor{inputNumber / i};
//        std::cout << ((factor <= i) ? factor : i) << ", " << ((factor >= i) ? factor : i) << '\n';
//    }
//}
