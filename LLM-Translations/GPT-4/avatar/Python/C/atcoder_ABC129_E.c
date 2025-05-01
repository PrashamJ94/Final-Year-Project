
#include <stdio.h>

#define mod 1000000007
#define MAX 100000

long long dp[MAX + 1][2];

int main() {
    char l[MAX + 1];
    scanf("%s", l);
    int n = strlen(l);
    dp[0][0] = 1;

    for (int i = 0; l[i]; i++) {
        if (l[i] == '0') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = (dp[i][1] * 3) % mod;
        } else {
            dp[i + 1][0] = (dp[i][0] * 2) % mod;
            dp[i + 1][1] = (dp[i][0] + (dp[i][1] * 3) % mod) % mod;
        }
    }
    
    printf("%lld\n", (dp[n][0] + dp[n][1]) % mod);
    return 0;
}

//End of Code.
