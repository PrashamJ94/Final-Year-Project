#include<stdio.h>
#include<stdlib.h>

int A[100005], N;
int dp[100005][2], dp_size;

int is_possible(int K) {
    dp_size = 1;
    dp[0][0] = A[0];
    dp[0][1] = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] <= dp[dp_size - 1][0]) {
            while (dp_size > 0 && dp[dp_size - 1][0] >= A[i]) dp_size--;
            dp[dp_size][0] = A[i];
            dp[dp_size++][1] = 0;
        } else {
            dp[dp_size][0] = A[i];
            dp[dp_size++][1] = 0;
        }
        int is_added = 0;
        for (int j = dp_size - 1; j >= 0; j--) {
            if (dp[j][1] < K - 1) {
                while (dp_size > 0 && dp[dp_size - 1][0] > dp[j][0] - 1) dp_size--;
                dp[dp_size][0] = dp[j][0] - 1;
                dp[dp_size++][1] = dp[j][1] + 1;
                is_added = 1;
                break;
            }
        }
        if (!is_added) return 0;
    }
    return 1;
}

int bis(int x, int y) {
    if (y == x + 1) return y;
    else if (is_possible((x + y) / 2)) return bis(x, (x + y) / 2);
    else return bis((x + y) / 2, y);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    printf("%d\n", bis(0, N));
    return 0;
}
