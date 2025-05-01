#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

void solver() {
    int N;
    scanf("%d", &N);
    int action[N][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &action[i][j]);
        }
    }

    int dp[N][3];

    for (int i = 0; i < 3; i++) {
        dp[0][i] = action[0][i];
    }

    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i - 1][1] + action[i][0], dp[i - 1][2] + action[i][0]);
        dp[i][1] = max(dp[i - 1][0] + action[i][1], dp[i - 1][2] + action[i][1]);
        dp[i][2] = max(dp[i - 1][0] + action[i][2], dp[i - 1][1] + action[i][2]);
    }

    printf("%d\n", max(max(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]));
}

int main() {
    solver();
    return 0;
}

// 
