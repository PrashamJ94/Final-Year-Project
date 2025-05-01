#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int diff = (*(int *)a % 10) - (*(int *)b % 10);
    return (diff == 0) ? (*(int *)a - *(int *)b) : diff;
}

int main() {
    int a[5], r[5], ans = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        r[i] = a[i] % 10;
    }

    qsort(a, 5, sizeof(int), compare);

    for (int i = 0; i < 4; i++) {
        if (a[i] % 10 == 0) {
            ans += a[i];
        } else {
            ans += a[i] + (10 - r[i]);
        }
    }

    ans += a[4];
    printf("%d\n", ans);

    return 0;
}

// //End of Code
