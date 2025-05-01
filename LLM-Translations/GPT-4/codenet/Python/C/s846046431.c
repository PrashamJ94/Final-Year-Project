#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    qsort(A, N, sizeof(int), compare);

    int S = 0;
    for (int i = 0; i < N; i++) {
        S += A[i];
    }

    for (int i = 0; i < M; i++) {
        if ((double)A[i] / S - 1.0 / (4 * M) < 0) {
            printf("No\n");
            break;
        }
    }

    printf("Yes\n");

    return 0;
}
// 
