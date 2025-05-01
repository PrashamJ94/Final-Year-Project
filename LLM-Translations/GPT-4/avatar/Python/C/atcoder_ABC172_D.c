#include <stdio.h>

int main() {
    int N, i;
    long long ans = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        ans += i * (N / i) * (N / i + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
} // End of Code.
