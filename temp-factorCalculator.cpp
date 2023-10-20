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
