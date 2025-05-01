
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);

    while (M) {
        A[N-1] /= 2;
        M -= 1;
        int i = N - 2;
        while (M && (-N <= i && A[i] >= A[N-1])) {
            A[i] /= 2;
            M -= 1;
            i -= 1;
        }
        qsort(A, N, sizeof(int), cmp);
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    printf("%d\n", sum);

    return 0;
}
// 


