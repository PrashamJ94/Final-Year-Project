#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[2][N];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int ans[N];
    int count;

    for (int i = 0; i < N; i++) {
        count = 0;
        for (int j = 0; j <= i; j++) {
            count += A[0][j];
        }
        for (int k = i; k < N; k++) {
            count += A[1][k];
        }
        ans[i] = count;
    }

    int max = ans[0];
    for (int i = 1; i < N; i++) {
        if (ans[i] > max) {
            max = ans[i];
        }
    }

    printf("%d\n", max);

    return 0;
}
// 
