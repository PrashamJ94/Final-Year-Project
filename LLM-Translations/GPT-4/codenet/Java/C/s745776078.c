#include <stdio.h>

int main() {
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int A[n][m], b[m];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n; i++) {
        int c = 0;
        for (j = 0; j < m; j++) {
            c += A[i][j] * b[j];
        }
        printf("%d\n", c);
    }

    return 0;
}
/*  */
