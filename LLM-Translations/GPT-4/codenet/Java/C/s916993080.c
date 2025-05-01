#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, i, j;
    scanf("%d", &n);
    int arr[n][3];
    for (i = 0; i < n; ++i) {
        for (j = 0; j < 3; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    int dp[n][3];
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (i = 1; i < n; ++i) {
        for (j = 0; j < 3; ++j) {
            if (j == 0)
                dp[i][j] = max(arr[i][0] + dp[i - 1][1], arr[i][0] + dp[i - 1][2]);
            if (j == 1)
                dp[i][j] = max(arr[i][1] + dp[i - 1][0], arr[i][1] + dp[i - 1][2]);
            if (j == 2)
                dp[i][j] = max(arr[i][2] + dp[i - 1][1], arr[i][2] + dp[i - 1][0]);
        }
    }
    int max_value = -1;
    for (i = 0; i < 3; ++i) {
        if (dp[n - 1][i] > max_value) max_value = dp[n - 1][i];
    }
    printf("%d\n", max_value);
    return 0;
}
// 
