#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modPow(ll b, ll e, ll mod) {
    ll ans = 1;
    ll x = b % mod;
    for (ll y = e; y != 0; y >>= 1) {
        if ((y & 1) == 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
    }
    return ans;
}

ll modInv(ll x, ll mod) {
    return modPow(x, mod - 2, mod);
}

ll modDiv(ll a, ll b, ll mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll lcm = 1;
    for (ll ai : A) {
        lcm = lcm / __gcd(lcm, ai) * ai;
    }

    ll mod = 1e9 + 7;
    ll modLcm = lcm % mod;
    ll ans = 0;
    for (ll ai : A) ans = (ans + modDiv(modLcm, ai, mod)) % mod;
    cout << ans << "\n";

    return 0;
}
// //End of Code
