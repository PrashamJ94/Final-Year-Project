
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int, int, int, int, int, int, int, int, int>> F(n);
    std::vector<std::tuple<int, int, int, int, int, int, int, int, int, int, int>> P(n);
    int64_t ans = -1e18;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            int f;
            std::cin >> f;
            std::get<j>(F[i]) = f;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) {
            int p;
            std::cin >> p;
            std::get<j>(P[i]) = p;
        }
    }

    for (int i = 1; i < (1 << 10); ++i) {
        int64_t tmp = 0;
        std::vector<int> lst(n, 0);
        for (int j = 0; j < 10; ++j) {
            if ((i >> j) & 1) {
                for (int k = 0; k < n; ++k) {
                    lst[k] += std::get<j>(F[k]);
                }
            }
        }
        for (int k = 0; k < n; ++k) {
            tmp += std::get<lst[k]>(P[k]);
        }
        ans = std::max(ans, tmp);
    }

    std::cout << ans << std::endl;

    return 0;
}

// 
