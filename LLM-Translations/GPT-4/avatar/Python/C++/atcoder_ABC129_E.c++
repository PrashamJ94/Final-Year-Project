#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    string l;
    cin >> l;
    int n = l.length();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        if(l[i] == '0'){
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][1] * 3 % mod;
        }
        else{
            dp[i+1][0] += dp[i][0] * 2 % mod;
            dp[i+1][1] += dp[i][0] + dp[i][1] * 3 % mod;
        }
        dp[i+1][0] %= mod;
        dp[i+1][1] %= mod;
    }
    cout << (dp[n][0] + dp[n][1]) % mod << "\n";
    return 0;
} // End of Code
