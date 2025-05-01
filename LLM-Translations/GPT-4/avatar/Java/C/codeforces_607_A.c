
#include <stdio.h>
#include <stdlib.h>

int main() {
    int max = 0;
    int n;
    scanf("%d", &n);
    int beacon[1000001] = {0};
    int dp[1000001] = {0};
    int a;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d", &beacon[a]);
    }

    if (beacon[0] != 0) {
        dp[0] = 1;
    }

    for (int i = 1; i < 1000001; i++) {
        if (beacon[i] != 0 && beacon[i] < i) {
            dp[i] = dp[i - beacon[i] - 1] + 1;
        } else if (beacon[i] != 0) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1];
        }
        max = (max > dp[i]) ? max : dp[i];
    }

    printf("%d", n - max);
    return 0;
}

//End of Code
