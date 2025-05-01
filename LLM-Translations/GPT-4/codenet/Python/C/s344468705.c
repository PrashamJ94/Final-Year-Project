#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int bisect_right(int *dp, int num, int len) {
    int left = 0, right = len;
    while (left < right) {
        int mid = (left + right) / 2;
        if (dp[mid] <= num) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void solve() {
    int n, num, i, idx;
    scanf("%d", &n);
    int dp[n+1];
    dp[0] = -INT_MAX;
    int len = 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        num = -num;
        if (num >= dp[len-1]) {
            dp[len++] = num;
        } else {
            idx = bisect_right(dp, num, len);
            dp[idx] = num;
        }
    }
    printf("%d\n", len - 1);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
// 
