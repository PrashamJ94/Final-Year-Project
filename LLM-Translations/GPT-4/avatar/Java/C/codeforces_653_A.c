#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, i;
    scanf("%d", &n);

    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    int unique = 0, last = -1;
    for (i = 0; i < n; i++) {
        if (a[i] != last) {
            a[unique++] = a[i];
            last = a[i];
        }
    }

    bool found = false;
    for (i = 0; i < unique - 2; i++) {
        if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
            found = true;
            break;
        }
    }

    printf(found ? "YES\n" : "NO\n");

    return 0;
}

// //End of Code.
