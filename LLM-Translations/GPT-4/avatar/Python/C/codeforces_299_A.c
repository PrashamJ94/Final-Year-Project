#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {
    int n, i, a[1000];

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);
    
    for(i = 1; i < n; i++) {
        if(a[i] % a[0] != 0) {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d\n", a[0]);

    return 0;
}

// End of Code
