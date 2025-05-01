#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K, d;
    scanf("%d %d", &N, &K);

    int *A = (int *) calloc(N, sizeof(int));

    for (int i = 0; i < K; i++) {
        scanf("%d", &d);
        for (int j = 0; j < d; j++) {
            int temp;
            scanf("%d", &temp);
            A[temp - 1] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            count++;
        }
    }

    printf("%d\n", count);
    free(A);

    return 0;
}
// 
