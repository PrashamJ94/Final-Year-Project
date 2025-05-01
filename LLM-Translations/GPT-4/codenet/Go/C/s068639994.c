#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int rev_cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int n;
    scanf("%d", &n);

    int ls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ls[i]);
    }

    int lsRev[n];
    memcpy(lsRev, ls, n * sizeof(int));
    qsort(ls, n, sizeof(int), cmp);
    qsort(lsRev, n, sizeof(int), rev_cmp);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int p = min(ls[i], ls[j]);
            int q = max(ls[i], ls[j]);
            int x = q - p;
            int y = q + p;

            int l = 0;
            while (l < n && ls[l] <= x) {
                l++;
            }

            int r = n - 1;
            while (r >= 0 && lsRev[r] >= y) {
                r--;
            }

            int sum = r - l + 1;
            if (i >= l && i <= r) {
                sum--;
            }
            if (j >= l && j <= r) {
                sum--;
            }
            sum = max(0, sum);
            ans += sum;
        }
    }

    ans /= 3;
    printf("%d\n", ans);

    return 0;
}

// 
