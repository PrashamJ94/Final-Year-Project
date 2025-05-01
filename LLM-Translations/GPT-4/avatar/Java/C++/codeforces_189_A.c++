#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int maxn = 4010;
    vector<int> arr = {a, b, c};
    vector<int> dp(maxn, numeric_limits<int>::min());
    dp[0] = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < dp.size(); j++) {
            dp[j] = max(dp[j], dp[j - arr[i]] + 1);
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}

// //End of Code.
