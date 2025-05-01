#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getPoints(int n, int k, int l, int r, int sAll, int sk, int *ans) {
    memset(ans, l, n * sizeof(int));
    sAll -= sk + (n - k) * l;
    sk -= k * l;
    while (sk > 0) {
        int idx = n - 1;
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++;
            sk--;
        }
    }
    while (sAll > 0) {
        int idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++;
            sAll--;
        }
    }
}

int main() {
    int n, k, l, r, sAll, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sAll, &sk);
    int *ans = (int *)malloc(n * sizeof(int));
    getPoints(n, k, l, r, sAll, sk, ans);
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    free(ans);
    return 0;
}

// //End of Code
