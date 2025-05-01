#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD1 1000000007
#define MOD2 998244353
long long tenmod[100005];
long long inv9 = modInv(9);

long long modInv(long long x) {
    return modPow(x, MOD2 - 2);
}

long long modPow(long long x, long long y) {
    long long z = 1;
    while (y > 0) {
        if (y % 2 == 0) {
            x = (x * x) % MOD2;
            y /= 2;
        } else {
            z = (z * x) % MOD2;
            y--;
        }
    }
    return z;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    tenmod[0] = 1;
    for (int j = 1; j <= N; j++) {
        tenmod[j] = (tenmod[j-1] * 10LL) % MOD2;
    }
    // Implement the remaining logic, functions, and data structures from the Java code
    return 0;
}
