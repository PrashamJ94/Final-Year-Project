
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

const int mod = 1000000007;

int main() {
    int h, n;
    std::cin >> h >> n;
    int a = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        a += temp;
    }

    if (h > a) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}

// 
