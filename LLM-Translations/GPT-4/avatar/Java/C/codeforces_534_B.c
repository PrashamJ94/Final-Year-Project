#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1150

int main() {
    int v1, v2, t, d;
    scanf("%d %d %d %d", &v1, &v2, &t, &d);

    long long dp[t - 1][MAX];

    for (int i = 0; i < t - 1; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = -(long long)(1e17);
        }
    }

    dp[0][v1] = v1;

    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int x = 0; x <= d; x++) {
                if (j + x < MAX) {
                    dp[i][j] = fmax(dp[i][j], dp[i - 1][j + x] + j);
                }
            }

            for (int x = d; x >= 0; x--) {
                if (j - x >= 0) {
                    dp[i][j] = fmax(dp[i][j], dp[i - 1][j - x] + j);
                }
            }
        }
    }

    long long ans = LLONG_MIN;

    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < MAX; j++) {
            if (abs(j - v2) <= d) {
                ans = fmax(ans, dp[i][j] + v2);
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
// //End of Code
