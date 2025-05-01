#include <stdio.h>
#include <stdlib.h>

int main() {
    long long X, K, D;
    scanf("%lld %lld %lld", &X, &K, &D);

    long long r = X / D;
    if (abs(r) > K) {
        printf("%lld\n", abs(X) - K * D);
        return 0;
    }
    long long a = X - r * D;
    if ((K - r) % 2 == 0) {
        printf("%lld\n", a);
    } else {
        printf("%lld\n", abs(D - a));
    }

    return 0;
}
// 
