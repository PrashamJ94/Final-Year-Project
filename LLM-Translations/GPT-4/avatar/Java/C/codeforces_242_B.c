#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int left = INT_MAX, right = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        if (left > a[i]) left = a[i];
        if (right < b[i]) right = b[i];
    }

    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            printf("%d\n", i + 1);
            free(a);
            free(b);
            return 0;
        }
    }

    printf("-1\n");
    free(a);
    free(b);
    return 0;
}

// //End of Code
