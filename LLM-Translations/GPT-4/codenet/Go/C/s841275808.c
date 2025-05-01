#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, i;
    scanf("%d", &N);

    int X[N], Y[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &X[i]);
        Y[i] = X[i];
    }

    qsort(Y, N, sizeof(int), compare);
    int m1 = Y[N / 2 - 1];
    int m2 = Y[N / 2];

    for (i = 0; i < N; i++) {
        if (X[i] <= m1) {
            printf("%d\n", m2);
        } else {
            printf("%d\n", m1);
        }
    }

    return 0;
}
// 
