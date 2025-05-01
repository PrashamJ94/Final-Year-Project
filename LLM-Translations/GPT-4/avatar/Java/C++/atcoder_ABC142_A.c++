#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double input, countOdd;
    std::cin >> input;

    countOdd = std::round(input / 2);
    double result = countOdd / input;

    std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    
    return 0;
}

// //End of Code.
