
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int mod = 1000000007;

// Function to compare integers for qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate exponentiation by squaring
int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (long long)res * a % mod;
        }
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, i, ans = 0;
    scanf("%d", &n);

    int c[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    qsort(c, n, sizeof(int), cmp);

    for (i = 0; i < n; i++) {
        ans = (ans + (long long)(n + 1 - i) * c[i] % mod) % mod;
    }

    printf("%d\n", (long long)ans * modpow(4, n - 1) % mod);

    return 0;
}

// 
