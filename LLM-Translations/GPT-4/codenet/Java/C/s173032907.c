#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long cost1 = 0;
    long cost2 = 0;
    int current1 = 0;
    int current2 = 0;
    long dp1[n];
    long dp2[n];
    for (i = 0, j = n - 1; i < n; i++, j--) {
        cost1 += abs(a[i] - current1);
        current1 = a[i];
        dp1[i] = cost1;
        cost2 += abs(a[j] - current2);
        current2 = a[j];
        dp2[j] = cost2;
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf("%ld\n", dp2[i + 1] + abs(a[1]));
        } else if (i == n - 1) {
            printf("%ld\n", dp1[i - 1] + abs(a[i - 1]));
        } else {
            printf("%ld\n", dp1[i - 1] + dp2[i + 1] + abs(a[i - 1] - a[i + 1]));
        }
    }
    return 0;
}
// 
