#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    double s = (double)sum(a, n) / (4 * m);
    if (a[m - 1] >= s) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
// 
