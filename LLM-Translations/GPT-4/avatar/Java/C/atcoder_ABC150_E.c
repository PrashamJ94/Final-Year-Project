#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

long power(long x, long n) {
    int mod = 1000000007;
    if (n == 0) {
        return 1;
    }
    long val = power(x, n / 2);
    val = val * val % mod;
    if (n % 2 == 1) {
        val = val * x % mod;
    }
    return val;
}

int main() {
    int n;
    scanf("%d", &n);
    int *c = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int mod = 1000000007;
    if (n == 1) {
        printf("%d\n", c[0] * 2 % mod);
        return 0;
    }

    qsort(c, n, sizeof(int), compare);

    long b = power(2, n);
    long a = power(2, n - 2);
    long ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        long val = a * i % mod;
        val *= c[n + 1 - i];
        val %= mod;
        ans += val;
        ans %= mod;
    }
    ans *= b;
    ans %= mod;
    printf("%ld\n", ans);

    free(c);
    return 0;
}

// //End of Code
