#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Pair {
    int l, r;
} Pair;

int n;
int a[2][20];
int memo[2][21][1048576];

int count_bits(int msk) {
    int count = 0;
    while (msk) {
        count += msk & 1;
        msk >>= 1;
    }
    return count;
}

int dp(int fliped, int idx, int msk) {
    if (msk == (1 << n) - 1) return 0;
    if (memo[fliped][idx][msk] != -1) return memo[fliped][idx][msk];
    int x = count_bits(msk);
    int ff = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if ((msk & (1 << i)) == 0) {
            int nf = x % 2;
            if (idx == n || a[fliped][idx] <= a[(nf + (ff % 2)) % 2][i]) {
                ans = (ans < (ff + dp((nf + (ff % 2)) % 2, i, msk | 1 << i)) ? ans : (ff + dp((nf + (ff % 2)) % 2, i, msk | 1 << i)));
            }
            ff++;
        } else {
            x--;
        }
    }
    return memo[fliped][idx][msk] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < (1 << n); k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    int ans = dp(0, n, 0);
    printf("%d\n", (ans >= 100000000 ? -1 : ans));
    return 0;
}
// 
