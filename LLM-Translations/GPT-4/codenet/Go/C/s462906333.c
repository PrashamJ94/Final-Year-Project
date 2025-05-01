#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, x;
    scanf("%d %d", &n, &x);

    int a[n], v[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    memcpy(v, a, n * sizeof(int));

    int ans = INF;

    for (int k = 0; k < n; k++) {
        int kans = 0;

        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = min(v[i], a[n + i - k]);
            } else {
                v[i] = min(v[i], a[i - k]);
            }

            kans += v[i];
        }

        ans = min(ans, kans + k * x);
    }

    printf("%d\n", ans);

    return 0;
}

// 
