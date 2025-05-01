#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <iomanip>

int main() {
    int n;
    double ans = 0.0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        ans += 1 / static_cast<double>(temp);
    }
    std::cout << std::fixed << std::setprecision(12) << 1 / ans << std::endl;
    return 0;
}

// 
