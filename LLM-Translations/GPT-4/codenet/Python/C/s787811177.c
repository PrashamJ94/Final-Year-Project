
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    int sumA = ((int*)a)[0] + ((int*)a)[1];
    int sumB = ((int*)b)[0] + ((int*)b)[1];
    return sumB - sumA;
}

int main() {
    int n, taka = 0, aoki = 0;
    scanf("%d", &n);

    int ls[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ls[i][0], &ls[i][1]);
    }

    qsort(ls, n, sizeof(ls[0]), cmpfunc);

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            taka += ls[i][0];
        } else {
            aoki += ls[i][1];
        }
    }

    printf("%d\n", taka - aoki);
    return 0;
}
