#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int lower_bound(long *a, long t, int min, int length) {
    int max = length;
    while (min < max) {
        int mid = (min + max) / 2;
        if (t <= a[mid]) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    return min;
}

long min(long a, long b, long c, long d, long e, long f) {
    long min_val = LONG_MAX;
    long vals[] = {a, b, c, d, e, f};
    for (int i = 0; i < 6; i++) {
        if (vals[i] < min_val) min_val = vals[i];
    }
    return min_val;
}

int main() {
    int a, b, q;
    scanf("%d %d %d", &a, &b, &q);
    long s[a + 2], t[b + 2];
    s[0] = t[0] = -10000000000L;
    for (int i = 0; i < a; i++) {
        scanf("%ld", &s[i + 1]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%ld", &t[i + 1]);
    }
    s[a + 1] = t[b + 1] = 20000000000L;
    for (int i = 0; i < q; i++) {
        long x;
        scanf("%ld", &x);
        long sl = x - s[lower_bound(s, x + 1, 0, a + 2) - 1];
        long tl = x - t[lower_bound(t, x + 1, 0, b + 2) - 1];
        long sr = s[lower_bound(s, x, 0, a + 2)] - x;
        long tr = t[lower_bound(t, x, 0, b + 2)] - x;
        printf("%ld\n", min(
                sl > tl ? sl : tl,
                sr > tr ? sr : tr,
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
        ));
    }
    return 0;
}
