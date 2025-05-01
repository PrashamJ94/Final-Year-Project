#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

static const long mod = 1000000007;
static const int inf = (int)(1e9 / 2);

double dp[301][301][301];

double rec(int i, int j, int k, int n) {
    if (dp[i][j][k] != -1) return dp[i][j][k];
    double ret = 0;
    double p = ((double)i + j + k) / n;
    double pi = (double)i / n;
    double pj = (double)j / n;
    double pk = (double)k / n;
    ret += 1 / p;
    if (i > 0) ret += pi / p * rec(i - 1, j, k, n);
    if (j > 0) ret += pj / p * rec(i + 1, j - 1, k, n);
    if (k > 0) ret += pk / p * rec(i, j + 1, k - 1, n);
    return dp[i][j][k] = ret;
}

void solve() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    dp[0][0][0] = 0;
    int cnt[] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        cnt[a[i] - 1]++;
    }
    double ans = rec(cnt[0], cnt[1], cnt[2], n);
    printf("%lf\n", ans);
}

int main() {
    solve();
    return 0;
}
// 
