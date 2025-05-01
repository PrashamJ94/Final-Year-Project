#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coef;
    for (int i = 1; i <= sqrt(n); ++i) {
        coef.push_back((n / i) - (n / (i + 1)));
    }
    coef.insert(coef.end(), n - accumulate(coef.begin(), coef.end(), 0LL), 1);
    reverse(coef.begin(), coef.end());

    int nn = coef.size();
    vector<vector<int>> dp(k + 1, vector<int>(nn, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= k; ++i) {
        int tmp = 0;
        for (int j = nn - 1; j >= 0; --j) {
            tmp += dp[i - 1][nn - 1 - j];
            tmp %= MOD;
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= MOD;
        }
    }

    cout << accumulate(dp[k].begin(), dp[k].end(), 0LL) % MOD;

    return 0;
}
// End of Code.
