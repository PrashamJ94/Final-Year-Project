#include <iostream>
#include <cmath>

int main() {
    int X, K, D;
    std::cin >> X >> K >> D;

    int r = X / D;
    if (std::abs(r) > K) {
        std::cout << std::abs(X) - K * D << std::endl;
        return 0;
    }
    int a = X - r * D;
    if ((K - r) % 2 == 0) {
        std::cout << a << std::endl;
    } else {
        std::cout << std::abs(D - a) << std::endl;
    }

    return 0;
}
// 
