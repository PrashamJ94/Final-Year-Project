#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
constexpr int MOD = 1e9 + 7;

int modpow(int a, int p) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int halfP = p / 2;
        int half = modpow(a, halfP);
        return half * half % MOD;
    } else {
        return a * modpow(a, p - 1) % MOD;
    }
}

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> fact(N + 1, 1), inv(N + 1, 0);
    rep(i, N) {
        fact[i + 1] = fact[i] * (i + 1) % MOD;
        inv[i + 1] = (inv[i] + modpow(i + 1, MOD - 2)) % MOD;
    }
    int ans = 0;
    rep(i, N) {
        int temp = (inv[i + 1] + inv[N - i] - 1) % MOD;
        ans = (ans + A[i] * temp) % MOD;
    }
    ans = ans * fact[N] % MOD;
    cout << ans << endl;
    return 0;
}

// End of Code.
