#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int n, i, high = 1, tower, maximum = 1;
    scanf("%d", &n);
    tower = n;
    int l[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), cmpfunc);
    for (i = 1; i < n; i++) {
        if (l[i] == l[i - 1]) {
            tower -= 1;
            high += 1;
        } else {
            if (high > maximum) {
                maximum = high;
            }
            high = 1;
        }
    }
    if (high > maximum) {
        maximum = high;
    }
    printf("%d %d\n", maximum, tower);
    return 0;
}
// End of Code
