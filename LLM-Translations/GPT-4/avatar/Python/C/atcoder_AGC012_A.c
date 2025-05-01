#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int* A = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    qsort(A, n, sizeof(int), compare);

    int ans = 0;
    for(int i = n - 1; i >= n - 2*n; i -= 2) {
        ans += A[i];
    }

    printf("%d\n", ans);

    free(A);

    return 0;
}

// End of Code.
