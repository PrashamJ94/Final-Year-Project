#include <stdio.h>
#include <stdlib.h>

#define MAXN 3001
#define MAXT 3001

int N, T;
int time_value[MAXN][2];
int dp[MAXN][MAXT];

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    scanf("%d %d", &N, &T);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &time_value[i][0], &time_value[i][1]);
    }

    for (int t = 0; t < T; t++) {
        dp[0][t] = 0;
    }
    
    for (int n = 1; n <= N; n++) {
        dp[n][0] = 0;
        for (int t = 1; t < T; t++) {
            if (time_value[n][0] > t) {
                dp[n][t] = dp[n - 1][t];
            }
            else {
                dp[n][t] = max(dp[n - 1][t], time_value[n][1] + dp[n - 1][t - time_value[n][0]]);
            }
        }
    }

    int val_acum = time_value[N][1];
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];
    for (int n = N - 1; n > 0; n--) {
        val_acum += time_value[n][1];
        t -= time_value[n + 1][0];
        if (t < 0)
            break;
        else
            max_val = max(max_val, val_acum + dp[n - 1][t]);
    }

    printf("%d\n", max_val);

    return 0;
}

// End of Code.
