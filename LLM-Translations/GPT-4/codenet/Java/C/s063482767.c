
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, i, sum = 0;
    scanf("%d", &n);
    int queue[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    qsort(queue, n, sizeof(int), compare);

    for(i = 0; i < n - 1; i++) {
        sum += queue[i];
    }

    // Output
    printf("%s\n", queue[n-1] < sum ? "Yes" : "No");

    return 0;
}
