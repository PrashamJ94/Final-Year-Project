#include <stdio.h>

int main() {
    long long N, A, B;
    scanf("%lld%lld%lld", &N, &A, &B);
    long long mod = 1e9 + 7;
    long long ans = 0;
    long long rep = N / (A + B);
    ans += rep * A;
    long long res = N - rep * (A + B);
    ans += res < A ? res : A;
    printf("%lld\n", ans);
    return 0;
}

// End of Code.
