#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int v[n], c[n], dp[n];

    for (int i = 0; i < n; i++) {
        dp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int tmp = dp[i - 1] + (v[i - 1] - c[i - 1]);
        dp[i] = tmp > dp[i - 1] ? tmp : dp[i - 1];
    }

    int tmp = dp[n - 1] + (v[n - 1] - c[n - 1]);
    dp[n - 1] = tmp > dp[n - 1] ? tmp : dp[n - 1];

    printf("%d\n", dp[n - 1]);
    return 0;
}
// 
