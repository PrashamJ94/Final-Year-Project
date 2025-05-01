#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, l, r;
} point;

int compare(const void *a, const void *b) {
    point *pa = (point *)a;
    point *pb = (point *)b;
    return pa->r - pb->r;
}

int main() {
    int N, i, start, ans;
    scanf("%d", &N);
    point points[N];

    for (i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].l);
        points[i].r = points[i].x + points[i].l;
        points[i].l = points[i].x - points[i].l;
    }

    qsort(points, N, sizeof(point), compare);

    start = points[0].r;
    ans = 1;
    for (i = 0; i < N; i++) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
// 
