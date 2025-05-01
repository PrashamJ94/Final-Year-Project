#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int main() {
    int N = 0;
    scanf("%d", &N);
    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    int m = A[0];
    int M = A[0];
    for (int i = 0; i < N; i++) {
        if (A[i] < m) m = A[i];
        if (A[i] > M) M = A[i];
    }

    printf("%d\n", M - m);

    free(A);
    return 0;
}
// 
