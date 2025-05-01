#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

int main() {
    std::string line;
    std::getline(std::cin, line);
    int n = std::stoi(line);
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> a;

    int value;
    while (iss >> value) {
        a.push_back(value);
    }

    int ans = 0;
    int aPrev = 0;
    for (int i = 0; i < n; i++) {
        int aCurrent = a[i];
        if (aCurrent > i || aCurrent > aPrev + 1) {
            std::cout << -1 << std::endl;
            return 0;
        } else if (aCurrent == aPrev + 1) {
            ans++;
        } else {
            ans += aCurrent;
        }
        aPrev = aCurrent;
    }
    std::cout << ans << std::endl;

    return 0;
}

// 
