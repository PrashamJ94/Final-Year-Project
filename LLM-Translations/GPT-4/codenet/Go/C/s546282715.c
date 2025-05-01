#include <stdio.h>
#include <stdlib.h>

int getNextInt(FILE *fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    int n = getNextInt(fp);
    int m = getNextInt(fp);
    int *aa = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        aa[getNextInt(fp)] = 1;
    }

    int *dp = (int *)calloc(n + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (aa[i + ii]) {
                continue;
            }
            dp[i + ii] += dp[i];
            dp[i + ii] %= 1000000007;
        }
    }
    printf("%d\n", dp[n]);

    free(aa);
    free(dp);
    fclose(fp);
    return 0;
}
// 
