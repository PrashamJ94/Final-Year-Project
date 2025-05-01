
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ri() {
    int n;
    scanf("%d", &n);
    return n;
}

double ave(double s[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
    }
    return sum / (double)n;
}

double diff(double a, double b) {
    if (a > b) {
        return a - b;
    }
    return b - a;
}

int main() {
    int n = ri();
    double a[n];
    for (int i = 0; i < n; i++) {
        a[i] = (double)ri();
    }

    double average = ave(a, n);

    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double currentDiff = diff(a[i], average);
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            ansIndex = i;
        }
    }
    printf("%d\n", ansIndex);
    return 0;
}


