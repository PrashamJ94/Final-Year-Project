
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INF 10000000000.0

int main() {
    int n, i;
    scanf("%d", &n);

    int arrA[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arrA[i]);
    }

    int cumSumA[n + 1];
    cumSumA[0] = 0;
    for (i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    double ans = INF;
    for (i = 1; i < n; i++) {
        if (fabs((double)(cumSumA[n] - (cumSumA[i] * 2))) < ans) {
            ans = fabs((double)(cumSumA[n] - cumSumA[i] * 2));
        }
    }

    printf("%d\n", (int)ans);

    return 0;
}


