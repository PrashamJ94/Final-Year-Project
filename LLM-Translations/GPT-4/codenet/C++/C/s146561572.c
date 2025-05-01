#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#define sz(a) ((int)sizeof(a) / sizeof(a[0]))
#define all(x) x, x + sz(x)
#define pb push_back
#define endl '\n'
#define watch(x) printf(#x " : %d\n", x)

typedef long long ll;
typedef int* vi;
typedef int** vvi;
typedef int ii[2];

const int N = (int)(2e5) + 10;
const int K = (int)(2e6) + 10;
const int MOD = (int)(1e9) + 7;
const int INF = (int)(1e9) + 5;
const ll INF64 = 2e18;

void solve() {
    ll ans = 0;
    int n;
    scanf("%d", &n);
    // Contribution of The Nodes.
    for (int i = 1; i <= n; i++) {
        ans += i * 1ll * (n - i + 1);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        int a = u > v ? u : v;
        int b = u < v ? u : v;
        ans -= b * 1ll * (n - a + 1);
    }
    printf("%lld\n", ans);
}

int main() {
    int t;
    // scanf("%d", &t);
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
// 
