#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(2, std::vector<int>(n));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }

    std::reverse(a[1].begin(), a[1].end());

    std::vector<int> res_0(n), res_1(n);
    std::partial_sum(a[0].begin(), a[0].end(), res_0.begin());
    std::partial_sum(a[1].begin(), a[1].end(), res_1.begin());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int check = res_0[i] + res_1[n - 1 - i];
        ans = std::max(ans, check);
    }

    std::cout << ans << std::endl;

    return 0;
} // 
