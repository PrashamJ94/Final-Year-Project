
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    }
    else if (b < a && b < c) {
        return b;
    }
    else {
        return c;
    }
}

int main() {
    int q, h, s, d, n;
    scanf("%d %d %d %d", &q, &h, &s, &d);
    scanf("%d", &n);

    int best1L = min(q * 4, h * 2, s);
    int best2L;

    if (d < best1L * 2) {
        best2L = d;
    }
    else {
        best2L = best1L * 2;
    }

    if (n % 2 == 0) {
        printf("%d", best2L * (n / 2));
    }
    else {
        printf("%d", best2L * (n / 2) + best1L);
    }

    return 0;
}

// End of Code.
