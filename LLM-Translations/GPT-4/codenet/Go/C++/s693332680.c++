#include <iostream>

int main() {
    int x, a, b;
    std::cin >> x >> a >> b;

    if (b - a <= 0) {
        std::cout << "delicious" << std::endl;
    } else if (b - a <= x) {
        std::cout << "safe" << std::endl;
    } else {
        std::cout << "dangerous" << std::endl;
    }

    return 0;
}
// 
