#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

const int mod = 1000000007;

int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int ans = 0;
    sort(c.begin(), c.end());

    for (int i = 0; i < n; i++) {
        ans = (ans + (1LL * (n + 1 - i) * c[i]) % mod) % mod;
    }

    cout << (1LL * ans * modpow(4, n - 1)) % mod << endl;

    return 0;
}
// 
