
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k, i, sum = 0;
    scanf("%d %d", &n, &k);
    
    int li[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &li[i]);
    }

    qsort(li, n, sizeof(int), compare);

    for (i = 0; i < k; i++) {
        sum += li[i];
    }

    printf("%d\n", sum);
    return 0;
}


