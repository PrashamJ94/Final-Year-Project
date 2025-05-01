#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <stack>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = (int)1e8;
const ll INFL = (ll)1e17;
const ll e97 = (ll)1e9 + 7;

bool is_prime(ll a) {
    if (a == 1) return false;
    for (ll i = 2L; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

ll gcd(ll m, ll n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}

ll lcm(ll m, ll n) {
    ll ans = m / gcd(m, n);
    ans *= n;
    return ans;
}

ll modinv(ll a, ll p) {
    ll b = p, u = 1L, v = 0L;
    while (b > 0) {
        ll t = a / b;
        ll pe = a % b;
        a = b;
        b = pe;
        pe = u - t * v;
        u = v;
        v = pe;
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

ll pow10E97(ll ob, ll soeji, ll p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = log2(soeji) + 1;
    vl ob_pow_2pow(d);

    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    ll ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (ll)(1 << i)) {
            soeji -= (ll)(1 << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    vector<bool> flaged(n, false);

    ll pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    ll surp1 = 0;

    for (int i = 0; i < n; i++) {
        surp1 *= 2L;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1L);
    }

    ll surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2L;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1L);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            ll dw = surp9;

            ll dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1L);
            dw %= (pop1st - 1L);

            int ans = 1;
            while (dw != 0) {
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        }
        else {
            ll dw = surp1;

            ll dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1L);

            int ans = 1;
            while (dw != 0) {
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
// 
