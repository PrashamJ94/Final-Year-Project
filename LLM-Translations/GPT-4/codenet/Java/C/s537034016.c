#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long* dp;
int mod = 1000000007;

long dfs(int s);

int main() {
    int s;
    scanf("%d", &s);

    dp = (long*)malloc((s + 1) * sizeof(long));
    memset(dp, -1, (s + 1) * sizeof(long));
    dp[0] = 1;
    printf("%ld\n", dfs(s));
    free(dp);

    return 0;
}

long dfs(int s) {
    if (dp[s] != -1) {
        return dp[s];
    }

    long ret = 0;
    for (int i = s - 3; i >= 0; i--) {
        ret += dfs(i);
        ret %= mod;
    }
    return dp[s] = ret;
}
