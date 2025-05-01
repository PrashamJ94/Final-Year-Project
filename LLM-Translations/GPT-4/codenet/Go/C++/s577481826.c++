
#include <iostream>
#include <algorithm>

int main() {
    int a, b;
    std::cin >> a >> b;

    int ret = a + b;

    if (ret < (a - b)) {
        ret = a - b;
    }
    if (ret < (a * b)) {
        ret = a * b;
    }

    std::cout << ret << std::endl;

    return 0;
}

// 
