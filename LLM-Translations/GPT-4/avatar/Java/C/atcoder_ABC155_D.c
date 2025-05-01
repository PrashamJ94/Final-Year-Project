#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(long *)a > *(long *)b) - (*(long *)a < *(long *)b);
}

bool check(long x, int n, long k, long a[]) {
    long tot = 0;
    for (int i = 0; i < n; i++) {
        long now = a[i];
        int l = 0, r = n;
        if (now >= 0) {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] < x) l = c + 1;
                else r = c;
            }
            tot += l;
        } else {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] >= x) l = c + 1;
                else r = c;
            }
            tot += (n - l);
        }
        if ((long)a[i] * a[i] < x) tot--;
    }
    return (tot / 2 < k);
}

int main() {
    int n;
    long k;
    scanf("%d %ld", &n, &k);
    long a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &a[i]);
    }
    qsort(a, n, sizeof(long), compare);
    long INF = (long)(1e18) + 1;
    long l = -INF;
    long r = INF;
    while (l + 1 < r) {
        long c = (l + r) / 2;
        if (check(c, n, k, a)) l = c;
        else r = c;
    }
    printf("%ld\n", l);
    return 0;
}

// //End of Code
