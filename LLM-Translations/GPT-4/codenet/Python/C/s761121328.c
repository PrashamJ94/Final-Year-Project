#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int s = A[0] ^ A[1];
    for (int i = 2; i < N; i++) {
        s = s ^ A[i];
    }

    int B[N];
    for (int i = 0; i < N; i++) {
        B[i] = s ^ A[i];
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");
    return 0;
}
// 
