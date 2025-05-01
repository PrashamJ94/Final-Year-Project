#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef unsigned long long ull;
typedef struct {
    ll first;
    ll second;
} P;

int main() {
    ll N, X;
    scanf("%lld %lld", &N, &X);

    ll ans = 0;
    ll min = 1000000000;
    for (int i = 0; i < N; i++) {
        ll tmp;
        scanf("%lld", &tmp);
        X -= tmp;
        ans++;
        if (tmp < min) min = tmp;
    }

    ans += X / min;

    printf("%lld\n", ans);

    return 0;
}
// 
