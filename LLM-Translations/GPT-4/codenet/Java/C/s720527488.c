#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define INF (INT_MAX / 2)
#define LINF (LLONG_MAX / 2)

void sort(int *a, int size) {
    for (int i = size - 1; i >= 1; i--) {
        int t = rand() % i;
        int temp = a[i];
        a[i] = a[t];
        a[t] = temp;
    }
    qsort(a, size, sizeof(int), (int (*)(const void *, const void *)) strcmp);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int *manju = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &manju[i]);
    }

    int *boxlen = malloc(n * sizeof(int));
    int *boxcost = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &boxlen[i], &boxcost[i]);
    }

    sort(manju, m);

    int dp[m + 1][n + 1];
    memset(dp, 0, (m + 1) * (n + 1) * sizeof(int));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int len = (i + boxlen[j] >= m) ? m : i + boxlen[j];
            int cnt = 0;
            for (int k = i; k < len; k++) cnt += manju[m - 1 - k];
            dp[i][j] = dp[len][j + 1] + cnt - boxcost[j] > dp[i][j] ? dp[len][j + 1] + cnt - boxcost[j] : dp[i][j];
            dp[i][j] = dp[i][j + 1] > dp[i][j] ? dp[i][j + 1] : dp[i][j];
        }
    }

    printf("%d\n", dp[0][0]);

    free(manju);
    free(boxlen);
    free(boxcost);

    return 0;
}
// 
