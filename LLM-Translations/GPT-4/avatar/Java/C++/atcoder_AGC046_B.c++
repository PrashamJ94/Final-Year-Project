#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 998244353LL;
vector<vector<long long>> dp(3001, vector<long long>(3001));

void solve(int A, int B, int C, int D) {
    dp[A][B] = 1;
    for (int c = A; c <= C; c++) {
        for (int d = B; d <= D; d++) {
            if (c == A && d == B) {
                continue;
            }
            long long ans = 0;
            if (c > A) {
                long long part = dp[c - 1][d];
                ans = (part * d);
            }
            if (d > B) {
                long long part = dp[c][d - 1];
                ans = (ans + (part * c));
            }
            if (c > A && d > B) {
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1)));
            }
            dp[c][d] = ((ans % MOD) + MOD) % MOD;
        }
    }
    cout << dp[C][D] << endl;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    solve(A, B, C, D);
    return 0;
}

// //End of Code
