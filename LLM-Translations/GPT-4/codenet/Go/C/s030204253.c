#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    double x = *(const double *)a;
    double y = *(const double *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    double a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    for (int i = 0; i+1 < n; i++) {
        qsort(a, n, sizeof(double), compare);
        double na[n-1];
        for (int j = 2; j < n; j++) {
            na[j-1] = a[j];
        }
        na[0] = (a[0] + a[1]) / 2;
        n--;
        for (int j = 0; j < n; j++) {
            a[j] = na[j];
        }
    }
    printf("%lf\n", a[0]);
    return 0;
}
// 
