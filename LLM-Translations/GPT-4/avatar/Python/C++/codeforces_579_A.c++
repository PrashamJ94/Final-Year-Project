#include <cmath>
#include <iostream>

int main() {
    int n, x = 1;
    std::cin >> n;
    while (std::fmod(std::log2(n), 1)) {
        x += 1;
        n -= std::pow(2, (int) (std::log2(n)));
    }
    std::cout << x;
    return 0;
} // End of Code
