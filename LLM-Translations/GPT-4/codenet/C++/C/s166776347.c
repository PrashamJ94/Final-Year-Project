
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

typedef long long ll;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)

ll mod = 1e9+7;

int main() {
    // Input
    ll N, K;
    scanf("%lld %lld", &N, &K);
    ll A[N];
    REP(i, N) scanf("%lld", &A[i]);

    // Solution
    ll ans1 = 0;
    REP(i, N) {
        REP(j, N) {
            if (i >= j) continue;
            if (A[i] > A[j]) ans1++;
            ans1 %= mod;
        }
    }

    ll count[2005] = {0};
    REP(i, N) {
        count[A[i] - 1]++;
    }

    ll ans2 = 0;
    ll remain = N;
    REP(i, 2005) {
        remain -= count[i];
        ans2 += count[i] * remain;
    }

    ll ans = 0;
    ll tmp = K * (K - 1);
    tmp /= 2;
    tmp %= mod;
    tmp *= ans2;
    tmp %= mod;
    ans += ans1 * K;
    ans %= mod;
    ans += tmp;
    ans %= mod;

    // Output
    printf("%lld\n", ans);

    return 0;
}


