#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int *a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, N, sizeof(int), compare);

    int sum = 0;
    for (int i = N; i < 2 * N; i += 2) {
        sum += a[i];
    }

    printf("%d\n", sum);
    free(a);

    return 0;
} // 
