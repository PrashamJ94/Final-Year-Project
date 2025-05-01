
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int n, i, x;
    scanf("%d", &n);

    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int b[n];
    int count = 0;

    for (i = 0; i < n; i++) {
        int v = a[i];
        int *position = (int *)bsearch(&v, b, count, sizeof(int), compare);

        if (position == NULL) {
            b[count++] = v;
            qsort(b, count, sizeof(int), compare);
        } else {
            *position = v;
        }
    }

    printf("%d\n", count);

    return 0;
}

// 
