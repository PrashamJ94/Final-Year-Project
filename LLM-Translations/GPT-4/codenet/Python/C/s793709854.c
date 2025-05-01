
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    int L[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &L[i][0], &L[i][1]);
    }

    int dp[N+1][T];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < T; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            if (j < L[i][0]) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i][j], dp[i][j-L[i][0]]+L[i][1]);
            }
        }
    }

    int used[N];
    for (int i = 0; i < N; i++) {
        used[i] = 0;
    }

    int B = dp[N][T-1];
    int j = T-1;
    for (int i = N-1; i >= 0; i--) {
        if (B == dp[i][j]) {
            continue;
        }
        B -= L[i][1];
        used[i] = 1;
        j -= L[i][0];
    }

    int ans = dp[N][T-1];
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (used[i] == 0) {
            c = max(c, L[i][1]);
        }
    }

    printf("%d\n", ans+c);

    return 0;
}
