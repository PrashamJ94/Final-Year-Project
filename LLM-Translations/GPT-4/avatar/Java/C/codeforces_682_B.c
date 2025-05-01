
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, i, c = 1;
    scanf("%d", &n);
    int list[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    qsort(list, n, sizeof(int), compare);
    for (i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }
    printf("%d\n", c);
    return 0;
}
// //End of Code


