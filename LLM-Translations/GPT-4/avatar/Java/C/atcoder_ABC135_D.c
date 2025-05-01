
#include <stdio.h>
#include <string.h>

#define MOD 1000000007

void solve(char *cs, int cs_len) {
    long long dp[cs_len][13];
    memset(dp, 0, sizeof(dp));
    int base = 1;

    for (int i = 0; i < cs_len; ++i) {
        if (cs[cs_len - 1 - i] == '?') {
            for (int pre = 0; pre < 13; ++pre) {
                for (int next = 0; next < 10; ++next) {
                    dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            int next = cs[cs_len - 1 - i] - '0';
            for (int pre = 0; pre < 13; ++pre) {
                dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        base = base * 10 % 13;
    }

    printf("%lld\n", dp[cs_len - 1][5]);
}

int main() {
    char cs[100001];
    scanf("%s", cs);
    int cs_len = strlen(cs);

    solve(cs, cs_len);

    return 0;
}

// //End of Code.
