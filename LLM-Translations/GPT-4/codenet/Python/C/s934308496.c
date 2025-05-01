#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int *m = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }

    qsort(m, n, sizeof(int), compare);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += m[i];
    }

    printf("%d\n", n + (x - sum) / m[0]);
    free(m);
    return 0;
}
// 
