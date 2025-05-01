
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, T;
    std::cin >> N >> T;
    std::vector<std::vector<int>> L(N, std::vector<int>(2));
    for (int i = 0; i < N; ++i) {
        std::cin >> L[i][0] >> L[i][1];
    }

    std::vector<std::vector<int>> dp(N+1, std::vector<int>(T, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < T; ++j) {
            if (j < L[i][0]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = std::max(dp[i][j], dp[i][j-L[i][0]]+L[i][1]);
            }
        }
    }

    std::vector<int> used;
    int B = dp[N][T-1];
    int j = T-1;
    for (int i = N-1; i >= 0; --i) {
        if (B == dp[i][j]) {
            continue;
        }
        B -= L[i][1];
        used.push_back(i);
        j -= L[i][0];
    }

    int ans = dp[N][T-1];
    int c = 0;
    for (int i = 0; i < N; ++i) {
        if (std::find(used.begin(), used.end(), i) != used.end()) {
            continue;
        }
        c = std::max(c, L[i][1]);
    }

    std::cout << ans+c << std::endl;
    return 0;
}


