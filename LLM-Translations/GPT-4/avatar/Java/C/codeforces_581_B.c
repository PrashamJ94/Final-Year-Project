#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i;
    long a[100000], dp[100001];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }

    memset(dp, -1, sizeof(dp));

    dp[n - 1] = a[n - 1];

    for (i = n - 1; i >= 0; i--) {
        dp[i] = dp[i + 1] > a[i] ? dp[i + 1] : a[i];
    }

    for (i = 0; i < n; i++) {
        if (a[i] > dp[i + 1]) {
            printf("0 ");
        } else {
            printf("%ld ", dp[i + 1] - a[i] + 1);
        }
    }

    printf("\n");

    return 0;
}

// //End of Code
