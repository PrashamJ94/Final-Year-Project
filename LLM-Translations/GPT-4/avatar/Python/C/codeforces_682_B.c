#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, i, c = 0;
    scanf("%d", &n);
    int l[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    qsort(l, n, sizeof(int), compare);

    for(i = 0; i < n; i++) {
        if(l[i] > c) {
            c++;
        }
    }

    printf("%d", c + 1);

    return 0;
}


/* End of Code */
