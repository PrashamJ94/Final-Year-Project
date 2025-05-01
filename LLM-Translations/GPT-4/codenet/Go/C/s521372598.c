#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int abs(int n) {
    return (n < 0) ? -n : n;
}

void solve() {
    int n, i, ans = 0;
    scanf("%d", &n);

    int as[n], xs[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &as[i]);
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), compare);

    int b = xs[n / 2];
    for (i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}

// 
