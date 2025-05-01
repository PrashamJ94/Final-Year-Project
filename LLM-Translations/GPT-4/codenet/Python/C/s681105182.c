#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, n, r;
    double dif = INT_MAX, prev_dif = INT_MAX;
    scanf("%d", &N);
    int a_li[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &a_li[i]);
    }

    qsort(a_li, N, sizeof(int), cmp);

    n = a_li[N - 1];

    for (int i = 0; i < N - 1; i++) {
        double temp_dif = fabs(n / 2.0 - a_li[i]);
        if (temp_dif < dif) {
            r = a_li[i];
            prev_dif = dif;
            dif = temp_dif;
        }
    }

    printf("%d %d\n", n, r);

    return 0;
}
