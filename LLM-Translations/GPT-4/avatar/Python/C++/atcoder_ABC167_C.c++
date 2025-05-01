#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> c(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) {
            cin >> c[i][j];
        }
    }
    int ans = 1e9;
    for (int bit = 0; bit < (1 << n); bit++) {
        vector<int> sum(m);
        int cost = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                cost += c[i][0];
                for (int j = 0; j < m; j++) {
                    sum[j] += c[i][j + 1];
                }
            }
        }
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (sum[j] < x) ok = false;
        }
        if (ok) ans = min(ans, cost);
    }
    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
// End of Code.
