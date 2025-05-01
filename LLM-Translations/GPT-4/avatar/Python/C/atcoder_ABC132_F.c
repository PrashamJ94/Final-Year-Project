#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define mod 1000000007

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int coef[n];
    int i;

    for (i = 1; i <= (int) sqrt(n); i++) {
        coef[i - 1] = (n / i) - (n / (i + 1));
    }
    int remaining = n - i + 1;
    for (; i <= n; i++) {
        coef[i - 1] = 1;
    }

    int nn = n;
    int dp[k + 1][nn];
    for (i = 0; i < k + 1; i++) {
        for (int j = 0; j < nn; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    for (i = 1; i <= k; i++) {
        int tmp = 0;
        for (int j = nn - 1; j >= 0; j--) {
            tmp += dp[i - 1][nn - 1 - j];
            tmp %= mod;
            dp[i][j] = coef[j] * tmp;
            dp[i][j] %= mod;
        }
    }

    int sum = 0;
    for (i = 0; i < nn; i++) {
        sum += dp[k][i];
        sum %= mod;
    }
    printf("%d\n", sum);

    return 0;
}
// End of Code
