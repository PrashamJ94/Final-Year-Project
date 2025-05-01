#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int A[M];
    int A_sum = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d", &A[i]);
        A_sum += A[i];
    }

    if (N - A_sum >= 0) {
        printf("%d\n", N - A_sum);
    } else {
        printf("-1\n");
    }

    // 
    return 0;
}
