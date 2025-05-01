#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= 2; ++j) cin >> arr[i][j];
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < 3; ++j){
            if (j == 0)
                dp[i][j] = max(arr[i][0] + dp[i-1][1], arr[i][0] + dp[i-1][2]);
            if (j == 1)
                dp[i][j] = max(arr[i][1] + dp[i-1][0], arr[i][1] + dp[i-1][2]);
            if (j == 2)
                dp[i][j] = max(arr[i][2] + dp[i-1][1], arr[i][2] + dp[i-1][0]);
        }
    }
    int max_value = -1;
    for(int i = 0; i < 3; ++i)
        if (dp[n-1][i] > max_value) max_value = dp[n-1][i];
    cout << max_value << endl;
    return 0;
}
// 
