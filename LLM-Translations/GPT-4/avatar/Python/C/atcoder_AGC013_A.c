#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i = 1, ans = 0;
    scanf("%d", &N);

    int *A = (int*)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < N; i++) {
        if(A[i] != A[i+1]) {
            A[i++] = A[i];
        }
    }
    N = i;

    while (i < N - 1) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;
            i++;
        }
        i++;
    }
    printf("%d", ans + 1);
    free(A);
    return 0;
}

// End of Code
