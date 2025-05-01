
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
map<string, int> memo[101];

bool ok(string last4) {
    for(int i = 0; i < 4; i++) {
        string t = last4;
        if(i >= 1)
            swap(t[i], t[i - 1]);
        if(t.find("AGC") != string::npos)
            return false;
    }
    return true;
}

int dfs(int cur, string last3) {
    if(memo[cur].count(last3))
        return memo[cur][last3];
    if(cur == n)
        return 1;
    int ret = 0;
    for(char c : "ACGT") {
        if(ok(last3 + c))
            ret = (ret + dfs(cur + 1, last3.substr(1) + c)) % mod;
    }
    return memo[cur][last3] = ret;
}

int main() {
    cin >> n;
    cout << dfs(0, "TTT") << endl;
    return 0;
}

// End of Code.
