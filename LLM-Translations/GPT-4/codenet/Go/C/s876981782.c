#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    if (*(double *)a < *(double *)b) return -1;
    if (*(double *)a > *(double *)b) return 1;
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    double values[N];
    for (int i = 0; i < N; i++) {
        scanf("%lf", &values[i]);
    }

    qsort(values, N, sizeof(double), compare);
    double generated = 0;
    for (int i = 0; i < N - 1; i++) {
        generated = (values[i] + values[i + 1]) / 2;
        values[i + 1] = generated;
    }

    printf("%lf\n", generated);
    return 0;
}
// 
