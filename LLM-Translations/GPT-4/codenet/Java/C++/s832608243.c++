#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;
    bool flag = false;
    for (int i = 1; i <= 100000; i++) {
        if (std::floor(1.0 * i * 0.08) == a && b == std::floor(0.1 * i)) {
            std::cout << i << std::endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        std::cout << -1 << std::endl;
    }
    return 0;
}
// 
