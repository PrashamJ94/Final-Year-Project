#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    long long ans = (long long) 1e18;

    for (int i = 1; i <= (int) sqrt(n) + 1; i++) {
        if (n % i != 0) {
            continue;
        }
        int j = n / i;
        ans = fmin(ans, (long long) i + j - 2);
    }

    printf("%lld\n", ans);

    return 0;
} // 
