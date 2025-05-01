#include <stdio.h>

#define DEVISOR 1000000007

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    long long ans = 0;
    for (long long i = k; i <= n + 1; i++) {
        long long max = i * (2 * n - i + 1) / 2;
        long long min = i * (i - 1) / 2;
        ans += (max - min + 1) % DEVISOR;
    }
    printf("%lld\n", ans % DEVISOR);

    return 0;
}
// 
