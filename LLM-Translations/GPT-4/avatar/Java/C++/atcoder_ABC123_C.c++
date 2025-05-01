#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    long long N;
    std::cin >> N;
    long long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            std::cin >> min;
        }
        else {
            long long temp;
            std::cin >> temp;
            min = std::min(min, temp);
        }
    }
    std::cout << static_cast<long long>(std::ceil(static_cast<double>(N) / min)) + 4 << std::endl;
    return 0;
}

// //End of Code
