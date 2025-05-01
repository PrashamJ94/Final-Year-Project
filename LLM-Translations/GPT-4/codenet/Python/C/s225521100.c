#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];

    for (int i = 0; i < N; i++) {
        A[i] = 0;
    }

    for (int i = 0; i < K; i++) {
        int d;
        scanf("%d", &d);
        int AA[d];
        for (int j = 0; j < d; j++) {
            scanf("%d", &AA[j]);
            A[AA[j] - 1] = 1;
        }
    }

    int n = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            n += 1;
        }
    }
    printf("%d\n", n);
    return 0;
}
// 
