#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int v1, v2, t, d;
    std::cin >> v1 >> v2 >> t >> d;

    std::vector<std::vector<long long>> dp(t - 1, std::vector<long long>(1150, -(long long)(1e17)));
    dp[0][v1] = v1;

    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < 1150)
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j + x] + j);
            }
            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - x] + j);
                }
            }
        }
    }

    long long ans = LLONG_MIN;
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            if (std::abs(j - v2) <= d)
                ans = std::max(ans, dp[i][j] + v2);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

// //End of Code.
