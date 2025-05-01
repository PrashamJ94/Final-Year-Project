
#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;
int dp[maxn][maxn];
pair<int,int> tv[maxn];

int main() {
    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> tv[i].second >> tv[i].first;
    }
    sort(tv + 1, tv + n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < t; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j >= tv[i].second) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - tv[i].second] + tv[i].first);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < t; i++) {
        ans = max(ans, dp[n][i] + tv[n + 1 - i].first);
    }
    cout << ans << endl;
    return 0;
}

// End of Code
