
#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define MOD 1000000007
#define ll long long

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll fermat(ll x, ll y) {
    return x * pow(y, MOD - 2, MOD) % MOD;
}

ll min4(ll a, ll b, ll c, ll d) {
    return min(a, min(b, min(c, d)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d;
    cin >> n;
    ll best1L = min4(q * 4, h * 2, s, INF);
    ll best2L = min(d, best1L * 2);
    if (n % 2 == 0) {
        cout << best2L * (n / 2) << "\n";
    } else {
        cout << best2L * (n / 2) + best1L << "\n";
    }

    return 0;
}
// End of Code

In this C++ code the mathematical functions for gcd, lcm, and fermat's theorem have been written as separate functions. The Python min function for four parameters has been replaced with a C++ function named min4 that makes use of the C++ min function. The Python main code has been translated into a C++ main function. The Python sys.stdin.readline() function has been replaced with C++ cin, and the Python print function has been replaced with C++ cout.
