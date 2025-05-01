c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
    char Si[100001];
    scanf("%s", Si);
    size_t len = strlen(Si);
    char S[len + 1];
    for (size_t i = 0; i < len; i++) {
        S[i] = Si[len - i - 1];
    }
    S[len] = '\0';

    long long dp[13] = {0};
    dp[0] = 1;

    int d = 1;
    for (size_t i = 0; i < len; i++, d = (d * 10) % 13) {
        long long nd[13] = {0};
        char c = S[i];

        if (isdigit(c)) {
            int x = (c - '0') * d;

            for (int j = 0; j < 13; j++) {
                nd[(j + x) % 13] = dp[j];
            }
        } else {
            for (int xi = 0; xi < 10; xi++) {
                int x = xi * d;

                for (int j = 0; j < 13; j++) {
                    int ni = (j + x) % 13;
                    nd[ni] = (nd[ni] + dp[j]) % 1000000007;
                }
            }
        }

        memcpy(dp, nd, sizeof(dp));
    }

    printf("%lld\n", dp[5]);
    return 0;
}

// 
