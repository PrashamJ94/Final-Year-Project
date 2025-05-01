#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int first;
    char second[22];
} P;

int compare(const void *a, const void *b) {
    P *pa = (P *)a;
    P *pb = (P *)b;
    if (pa->first != pb->first)
        return pa->first - pb->first;
    return strcmp(pa->second, pb->second);
}

int main(void) {
    int n;
    P v[22];
    int d[33][22];
    int d_size[33];

    while (scanf("%d", &n) && n) {
        for (int i = 0; i < 33; i++) d_size[i] = 0;

        for (int i = 0; i < n; i++) {
            v[i].first = 0;
            scanf("%s", v[i].second);
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                int a;
                scanf("%d", &a);
                v[i].first += n - d_size[a];
                for (int k = 0; k < d_size[a]; k++) {
                    v[d[a][k]].first--;
                }
                d[a][d_size[a]++] = i;
            }
        }
        qsort(v, n, sizeof(P), compare);
        printf("%d %s\n", v[0].first, v[0].second);
    }
    return 0;
}
/*  */
