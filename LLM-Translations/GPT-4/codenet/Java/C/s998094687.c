#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, i;
    scanf("%d", &n);
    int a[3];
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        qsort(a, 3, sizeof(int), compare);
        if (pow(a[2], 2) == pow(a[0], 2) + pow(a[1], 2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
// 
