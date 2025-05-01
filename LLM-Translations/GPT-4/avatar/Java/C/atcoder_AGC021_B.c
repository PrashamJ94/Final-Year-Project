#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    double diff = *(double *)a - *(double *)b;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    int x[N], y[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for (int i = 0; i < N; ++i) {
        double thetas[N];
        int thetas_count = 0;

        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            thetas[thetas_count++] = atan2(y[j] - y[i], x[j] - x[i]);
        }

        qsort(thetas, thetas_count, sizeof(double), compare);
        thetas[thetas_count] = thetas[0] + 2 * M_PI;
        double ans = 0;

        for (int k = 0; k < N - 1; ++k)
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);

        printf("%.15f\n", ans / (M_PI * 2));
    }
    
    return 0;
}

// //End of Code
