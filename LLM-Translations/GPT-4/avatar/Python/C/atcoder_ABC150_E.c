#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

long long powmod(long long x, long long y, long long mod) {
    long long res = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main() {
    const long long mod = 1000000007;
    int n, i;
    scanf("%d", &n);
    int *c = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    qsort(c, n, sizeof(int), cmpfunc);

    long long b = powmod(2, 2 * n - 2, mod);
    long long a = (2 * b) % mod;
    long long ans = 0;
    for(i = 0; i < n; i++) {
        ans += c[i] * ((a + i * b) % mod);
        ans %= mod;
    }
    printf("%lld\n", ans);
    free(c);
    return 0;
}

// End of Code
