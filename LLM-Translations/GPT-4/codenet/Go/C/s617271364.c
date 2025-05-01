#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N, ss, ans, A, B, C;

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int abs(int a) {
    if (a < 0) {
        return a * -1;
    }
    return a;
}

void dfs(int *dp, int times, int *arr) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times+1, arr);
    }
}

int calc(int *dp, int *arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0;

    int memo[4] = {0};
    for (int i = 0; i < N; i++) {
        memo[dp[i]]++;
        if (dp[i] == 1) {
            AA += arr[i];
        } else if (dp[i] == 2) {
            BB += arr[i];
        } else if (dp[i] == 3) {
            CC += arr[i];
        }
    }
    cost += abs(A-AA) + abs(B-BB) + abs(C-CC);

    for (int i = 1; i < 4; i++) {
        int a = memo[i];
        if (a < 1) {
            cost += 10000;
        } else {
            cost += (a - 1) * 10;
        }
    }

    return cost;
}

int main() {
    scanf("%d %d %d %d", &N, &A, &B, &C);

    int *arr = malloc(N * sizeof(int));
    int *dp = malloc(N * sizeof(int));
    ans = 10000;
    ss = A + B + C;

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    dfs(dp, 0, arr);

    printf("%d\n", ans);

    free(arr);
    free(dp);
    return 0;
}

// 
