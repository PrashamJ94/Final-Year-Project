#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int po[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &po[i]);
        m -= po[i];
    }

    qsort(po, n, sizeof(int), compare);
    printf("%d\n", n + m / po[0]);

    return 0;
}
// 
