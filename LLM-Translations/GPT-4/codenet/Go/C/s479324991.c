#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    double num1 = *(double *)a;
    double num2 = *(double *)b;

    if (num1 < num2) {
        return -1;
    } else if (num1 > num2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    double arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    qsort(arr, n, sizeof(double), compare);

    double prev = arr[0];
    for (int i = 1; i < n; i++) {
        prev = (prev + arr[i]) / 2;
    }

    printf("%lf\n", prev);
    return 0;
}

/*  */
