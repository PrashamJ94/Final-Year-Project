
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void solve(int N, long X, long *x) {
    long *xsum = (long *)malloc((N + 1) * sizeof(long));
    xsum[0] = 0;
    for (int i = 0; i < N; i++) {
        xsum[i + 1] = xsum[i] + x[i];
    }
    long ans = X * N + 5 * xsum[N];
    for (int i = 1; i < N; i++) {
        long cost = X * i + 5 * (xsum[N] - xsum[N - i]);
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            if (cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[k > i ? k - i : 0]);
        }
        ans = ans < cost ? ans : cost;
    }
    printf("%ld\n", ans + N * X);
    free(xsum);
}

int main() {
    int N;
    long X;
    scanf("%d %ld", &N, &X);
    long *x = (long *)malloc(N * sizeof(long));
    for (int i = 0; i < N; i++) {
        scanf("%ld", &x[i]);
    }
    solve(N, X, x);
    free(x);
    return 0;
}

// //End of Code.
