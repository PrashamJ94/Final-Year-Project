#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <random>
#include <cstring>
#include <stdexcept>

using namespace std;

const int INF = numeric_limits<int>::max() / 2;
const long long LINF = numeric_limits<long long>::max() / 2;

void sort(vector<int> &a) {
    for (int i = a.size() - 1; i >= 1; i--) {
        int t = rand() % i;
        swap(a[i], a[t]);
    }
    sort(a.begin(), a.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    
    vector<int> manju(m);
    for (int i = 0; i < m; i++) {
        cin >> manju[i];
    }
    
    vector<int> boxlen(n), boxcost(n);
    for (int i = 0; i < n; i++) {
        cin >> boxlen[i] >> boxcost[i];
    }
    
    sort(manju);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int len = i + boxlen[j] >= m ? m : i + boxlen[j];
            int cnt = 0;
            for (int k = i; k < len; k++) {
                cnt += manju[m - 1 - k];
            }
            dp[i][j] = max(dp[i][j], dp[len][j + 1] + cnt - boxcost[j]);
            dp[i][j] = max(dp[i][j], dp[i][j + 1]);
        }
    }
    
    cout << dp[0][0] << endl;

    return 0;
}
// 
