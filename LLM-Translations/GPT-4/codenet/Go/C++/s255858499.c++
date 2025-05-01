#include <iostream>
#include <string>

int main() {
    int a, b;
    std::cin >> a;
    std::cin >> b;

    if (a * b % 2 != 0) {
        std::cout << "Odd" << std::endl;
    } else {
        std::cout << "Even" << std::endl;
    }

    return 0;
}
// 
