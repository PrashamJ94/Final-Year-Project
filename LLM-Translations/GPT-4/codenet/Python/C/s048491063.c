#include <stdio.h>

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    int train[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            train[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        train[l - 1][r - 1]++;
    }

    int accum[N + 1][N + 1];
    accum[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        accum[0][i] = 0;
        accum[i][0] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            accum[i][j] = accum[i - 1][j] + accum[i][j - 1] - accum[i - 1][j - 1] + train[i - 1][j - 1];
        }
    }

    for (int i = 0; i < Q; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        int v = accum[q][q] - accum[p - 1][q] - accum[q][p - 1] + accum[p - 1][p - 1];
        printf("%d\n", v);
    }

    return 0;
}
// 
