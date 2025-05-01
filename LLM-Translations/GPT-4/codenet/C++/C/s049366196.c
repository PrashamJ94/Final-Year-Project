#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef long long ll;
const int inf = 1e9;
const int mod = 1e9+7;

bool is_prime(ll x) {
    for (ll i = 2; i*i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int N;
    scanf("%d", &N);

    ll ans = 1;
    for (int i = 2; i <= N; i++) {
        if (is_prime((ll)i)) {
            int NN = N;
            int cnt = 0;
            while (NN) {
                cnt += NN/i;
                NN /= i;
            }
            ans *= cnt+1;
            ans %= mod;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
// 
