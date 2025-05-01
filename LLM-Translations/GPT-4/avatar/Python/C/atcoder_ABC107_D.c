#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *tree;
    int depth;
} BIT;

int bitsum(BIT *bit, int r) {
    int ret = 0;
    while (r) {
        ret += bit->tree[r];
        r ^= r & -r;
    }
    return ret;
}

void bitadd(BIT *bit, int i, int x) {
    i += 1;
    while (i <= bit->size) {
        bit->tree[i] += x;
        i += i & -i;
    }
}

int check(BIT *bit, int *a, int *b, int *d, int *_a, int n, int m, int X) {
    for (int i = 0; i < n; i++) {
        b[i + 1] = (a[i] >= X) * 2 - 1;
        b[i + 1] += b[i];
    }
    int c = b[0];
    for (int i = 1; i <= n; i++) {
        if (b[i] < c) c = b[i];
    }
    for (int i = 0; i <= n; i++) {
        b[i] -= c;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += bitsum(bit, b[i] + 1);
        bitadd(bit, b[i], 1);
    }
    return ans >= m;
}

int main() {
    int n;
    scanf("%d", &n);
    int m = n * (n + 1) / 4;
    int *a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int *_a = (int*) malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) _a[i] = a[i];
    qsort(_a, n, sizeof(int), compare);
    int *d = (int*) malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) d[_a[i]] = i;
    int *b = (int*) malloc((n + 1) * sizeof(int));
    b[0] = 0;
    BIT bit;
    bit.size = n + 1;
    bit.tree = (int*) malloc((n + 2) * sizeof(int));
    int t[2] = {n, 0};
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        if (check(&bit, a, b, d, _a, n, m, mid)) t[1] = mid;
        else t[0] = mid;
    }
    printf("%d\n", _a[t[1]]);
    free(a);
    free(b);
    free(bit.tree);
    free(d);
    free(_a);
    return 0;
}
/* End of Code */
