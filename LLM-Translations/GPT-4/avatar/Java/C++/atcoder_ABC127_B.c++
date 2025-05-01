#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
    int r, d;
    long long x;
    std::cin >> r >> d >> x;

    for (int i = 0; i < 10; ++i) {
        x = r * x - d;
        std::cout << x << std::endl;
    }

    return 0;
}

// //End of Code
