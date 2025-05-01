#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if (N % 9 == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
// 
