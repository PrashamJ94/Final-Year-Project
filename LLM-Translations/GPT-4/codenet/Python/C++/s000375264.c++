#include <iostream>

int main() {
    int X, t;
    std::cin >> X >> t;

    int answer;
    if (X > t) {
        answer = X - t;
    } else {
        answer = 0;
    }

    std::cout << answer << std::endl;
    return 0;
} // 
