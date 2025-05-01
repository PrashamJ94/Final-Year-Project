#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>

const int64_t d = 1000000007;

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    int64_t mdans[100002] = {0};
    for (int index = 0; index < p; index++) {
        int64_t n1;
        scanf("%" SCNd64, &n1);
        mdans[n1] = n1;
    }

    int64_t dp[100002] = {0};
    dp[0] = 1;
    dp[1] = 1;

    if (mdans[1] > 0) {
        dp[1] = 0;
    }

    for (int i = 2; i <= n; i++) {
        if (mdans[i] > 0) {
            continue;
        }
        dp[i] = (dp[i - 1] + dp[i - 2]) % d;
    }

    printf("%" PRId64 "\n", dp[n]);
    return 0;
}
// 
