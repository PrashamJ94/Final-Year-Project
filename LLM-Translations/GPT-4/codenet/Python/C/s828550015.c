#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int x, y, a, b, c;
    scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);
    
    int p[x], q[y], r[c];
    for (int i = 0; i < x; i++) scanf("%d", &p[i]);
    for (int i = 0; i < y; i++) scanf("%d", &q[i]);
    for (int i = 0; i < c; i++) scanf("%d", &r[i]);

    qsort(p, x, sizeof(int), compare);
    qsort(q, y, sizeof(int), compare);
    qsort(r, c, sizeof(int), compare);

    int pq[x+y];
    for (int i = 0; i < x; i++) pq[i] = p[i];
    for (int i = 0; i < y; i++) pq[x+i] = q[i];
    qsort(pq, x+y, sizeof(int), compare);

    for (int i = 0; i < (x+y < a+b ? x+y : a+b < c ? a+b : c); i++) {
        if (pq[i] < r[i]) {
            pq[i] = r[i];
        }
    }

    long long sum = 0;
    for (int i = 0; i < x+y; i++) sum += pq[i];
    printf("%lld\n", sum);

    return 0;
}
// 
