#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long *cumsum = (long *)malloc((n + 1) * sizeof(long));
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    long *b = (long *)malloc(n * (n + 1) / 2 * sizeof(long));
    int b_size = 0;
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b[b_size++] = cumsum[j + 1] - cumsum[i];
            max = max > (cumsum[j + 1] - cumsum[i]) ? max : (cumsum[j + 1] - cumsum[i]);
        }
    }

    long mask = 1;
    while (mask < max) {
        mask <<= 1;
    }

    while (mask > 0) {
        long *tmp = (long *)malloc(n * (n + 1) / 2 * sizeof(long));
        int tmp_size = 0;
        for (int i = 0; i < b_size; i++) {
            if ((b[i] & mask) != 0) {
                tmp[tmp_size++] = b[i];
            }
        }

        if (tmp_size >= k) {
            memcpy(b, tmp, tmp_size * sizeof(long));
            b_size = tmp_size;
        }

        mask >>= 1;
        free(tmp);
    }

    if (b_size < k) {
        printf("0\n");
    } else {
        long ans = -1;
        for (int i = 0; i < b_size; i++) {
            ans &= b[i];
        }

        printf("%ld\n", ans);
    }

    free(a);
    free(b);
    free(cumsum);
}

int main() {
    solve();

    return 0;
}

// 
