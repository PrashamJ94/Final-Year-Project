#include <iostream>
#include <cmath>

const int BASE = 3;

int main() {
    int input;
    std::cin >> input;
    std::cout << static_cast<int>(std::pow(input, BASE)) << std::endl;
    return 0;
}
// 
