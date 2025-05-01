#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

long long MOD = 1000000007;

long long f(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res = (res * i) % MOD;
    return res;
}

vector<int> toInts(string s) {
    vector<int> o;
    stringstream ss(s);
    int temp;
    while (ss >> temp) {
        o.push_back(temp);
    }
    return o;
}

void solve() {
    string input;
    getline(cin, input);
    vector<int> xx = toInts(input);

    int min = min(xx[0], xx[1]);
    int max = max(xx[0], xx[1]);
    long long res;
    if (min == max) {
        long long f_val = f(min);
        res = (2 * f_val * f_val) % MOD;
    } else if (min + 1 == max) {
        long long f_val = f(min);
        res = (f_val * ((f_val * max) % MOD)) % MOD;
    } else {
        res = 0;
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

// 
