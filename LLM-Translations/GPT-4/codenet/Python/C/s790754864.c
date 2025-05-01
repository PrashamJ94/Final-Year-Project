
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int fact(int n, int r) {
    return tgamma(n + 1) / (tgamma(n - r + 1) * tgamma(r + 1));
}

int main() {
    int N, K, R, i;
    long long int ans, mod = 1000000007;
    
    scanf("%d %d", &N, &K);
    R = N - K;

    for (i = 1; i <= K; i++) {
        if (N - K + 1 < i) {
            ans = 0;
        } else {
            ans = fact(R + 1, i) * fact(K - 1, i - 1);
        }
        printf("%lld\n", ans % mod);
    }

    return 0;
}
