#include <stdio.h>
#define MOD 1000000007

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b = b >> 1;
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    long long A[N];
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);
    long long _lcm = 1;
    for (int i = 0; i < N; i++)
        _lcm = (_lcm * A[i]) / gcd(_lcm, A[i]);
    long long ans = 0;
    for (int i = 0; i < N; i++)
        ans = (ans + power(A[i], MOD - 2)) % MOD;
    ans = (ans * _lcm) % MOD;
    printf("%lld\n", ans);
    return 0;
}

// End of Code
