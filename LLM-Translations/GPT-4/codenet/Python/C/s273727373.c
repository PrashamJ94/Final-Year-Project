#include <stdio.h>

int main() {
    int N, i, count;
    scanf("%d", &N);
    int A[N], B[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    count = 1;
    for (i = 0; i < N; i++) {
        B[A[i] - 1] = count;
        count++;
    }
    for (i = 0; i < N; i++) {
        printf("%d ", B[i]);
    }
    return 0;
}
// 
