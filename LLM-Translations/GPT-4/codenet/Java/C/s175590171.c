#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    long long sum = 0;
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
        if (a[i + 1] <= 2 * sum) {
            count++;
        } else {
            count = 0;
        }
    }
    printf("%d\n", count + 1);
    return 0;
}
// 
