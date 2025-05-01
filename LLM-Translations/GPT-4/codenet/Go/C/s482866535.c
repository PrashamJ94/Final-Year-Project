#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int get_next_int(FILE *fp) {
    int i;
    fscanf(fp, "%d", &i);
    return i;
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    int n = get_next_int(fp);
    int *mm = (int *) malloc((n + 1) * sizeof(int));
    int **dp = (int **) malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *) malloc((n + 1) * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        mm[i] = get_next_int(fp);
        mm[i + 1] = get_next_int(fp);
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; k++) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    printf("%d\n", dp[1][n]);

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(mm);
    fclose(fp);

    return 0;
}
// 
