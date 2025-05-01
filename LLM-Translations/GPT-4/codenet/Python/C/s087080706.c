#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);

    int *a = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, m, sizeof(int), compare);

    int i;
    for (i = 0; i < m; i++) {
        if (a[i] > x) {
            break;
        }
    }

    int ans = (i < m - i) ? i : m - i;
    printf("%d\n", ans);
    
    free(a);
    
    return 0;
} // 
