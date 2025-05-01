#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, check, ans = 0;
    scanf("%d", &n);
    int **a = (int **)malloc(2 * sizeof(int *));
    for (i = 0; i < 2; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int *res_0 = (int *)malloc(n * sizeof(int));
    int *res_1 = (int *)malloc(n * sizeof(int));
    res_0[0] = a[0][0];
    res_1[n - 1] = a[1][n - 1];
    for (i = 1; i < n; i++) {
        res_0[i] = res_0[i - 1] + a[0][i];
        res_1[n - 1 - i] = res_1[n - i] + a[1][n - 1 - i];
    }
    for (i = 0; i < n; i++) {
        check = res_0[i] + res_1[n - 1 - i];
        if (check > ans) {
            ans = check;
        }
    }
    printf("%d\n", ans);
    for (i = 0; i < 2; i++) {
        free(a[i]);
    }
    free(a);
    free(res_0);
    free(res_1);
    return 0;
}
// 
