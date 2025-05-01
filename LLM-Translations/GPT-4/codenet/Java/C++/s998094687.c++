#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(3);
    for (int i = 0; i < n; i++) {
        std::cin >> a[0] >> a[1] >> a[2];
        std::sort(a.begin(), a.end());
        if (std::pow(a[2], 2) == std::pow(a[0], 2) + std::pow(a[1], 2)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
// 
