#include <stdio.h>
#include <stdlib.h>

int nint() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int N = nint();
    int W = nint();

    int *v = (int *)malloc((N + 1) * sizeof(int));
    int *w = (int *)malloc((N + 1) * sizeof(int));

    for (int i = 1; i <= N; i++) {
        v[i] = nint();
        w[i] = nint();
    }

    int **sumV = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i < N + 1; i++) {
        sumV[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i - 1][i_sum];
        }

        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = (sumV[i - 1][i_sum] > sumV[i - 1][i_sum - w[i]] + v[i]) ? sumV[i - 1][i_sum] : sumV[i - 1][i_sum - w[i]] + v[i];
        }
    }

    printf("%d\n", sumV[N][W]);

    free(v);
    free(w);
    for (int i = 0; i < N + 1; i++) {
        free(sumV[i]);
    }
    free(sumV);

    return 0;
}

// 
