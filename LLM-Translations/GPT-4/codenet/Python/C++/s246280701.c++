
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    int ans = std::numeric_limits<int>::max();
    for (int i = 0; i <= 100; ++i) {
        int tmp_sum = 0;
        for (int j = 0; j < n; ++j) {
            tmp_sum += std::pow(abs(i - x[j]), 2);
        }
        if (tmp_sum < ans) {
            ans = tmp_sum;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}


