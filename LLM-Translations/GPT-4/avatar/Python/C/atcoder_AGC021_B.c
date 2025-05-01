#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int N;
    scanf("%d", &N);
    double* XY = malloc(2 * N * sizeof(double));
    for (int i = 0; i < 2 * N; i++) {
        scanf("%lf", &XY[i]);
    }
    for (int i = 0; i < N; i++) {
        double x = XY[2 * i];
        double y = XY[2 * i + 1];
        double* D = malloc((N - 1) * sizeof(double));
        int k = 0;
        for (int j = 0; j < N; j++) {
            if (j != i) {
                double X = XY[2 * j];
                double Y = XY[2 * j + 1];
                D[k++] = atan2(X - x, Y - y);
            }
        }
        qsort(D, N - 1, sizeof(double), (int (*)(const void*, const void*)) compare);
        D = realloc(D, N * sizeof(double));
        D[N - 1] = D[0] + 2 * PI;
        double ans = 0;
        for (int a = 0; a < N; a++) {
            double diff = D[a + 1] - D[a];
            if (diff >= PI) {
                ans = diff - PI;
            }
        }
        printf("%lf\n", ans / (2 * PI));
        free(D);
    }
    free(XY);
    return 0;
}

int compare(double* a, double* b) {
    if (*a < *b) return -1;
    if (*a > *b) return 1;
    return 0;
}

// End of Code
