#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char S[100001];
    scanf("%s", S);
    long MOD = 1000000007;
    long dp[100001][13] = {0};
    dp[0][0] = 1;

    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == '?') {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 13; k++) {
                    dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
                    dp[i + 1][(k * 10 + j) % 13] %= MOD;
                }
            }
        } else {
            for (int k = 0; k < 13; k++) {
                int x = S[i] - '0';
                dp[i + 1][(k * 10 + x) % 13] += dp[i][k];
                dp[i + 1][(k * 10 + x) % 13] %= MOD;
            }
        }
    }
    printf("%ld\n", dp[strlen(S)][5]);
    return 0;
}
// 
