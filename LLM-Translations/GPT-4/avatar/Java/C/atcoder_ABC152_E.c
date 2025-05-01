
#include <stdio.h>
#include <stdlib.h>

long long modPow(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

long long modInv(long long a, long long mod) {
    return modPow(a, mod - 2, mod);
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    long long lcm = 1;
    long long mod = 1000000007;
    for (int i = 0; i < N; i++) {
        lcm = lcm / gcd(lcm, A[i]) % mod * A[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + lcm * modInv(A[i], mod) % mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}

// //End of Code
