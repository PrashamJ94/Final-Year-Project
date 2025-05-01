#include <stdio.h>
#include <stdlib.h>

void rec(int N, int M, int Q, int *a, int *b, int *c, int *d, int *A, int *res) {
    if (N == 0) {
        int ans = 0;
        for (int i = 0; i < Q; i++) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                ans += d[i];
            }
        }
        if (ans > *res) {
            *res = ans;
        }
        return;
    }

    int last_max = (N == 1) ? 1 : A[N - 2];
    for (int i = last_max; i <= M; i++) {
        A[N - 1] = i;
        rec(N - 1, M, Q, a, b, c, d, A, res);
    }
}

void solve(int N, int M, int Q, int *a, int *b, int *c, int *d) {
    int res = 0;
    int *A = (int *)malloc(N * sizeof(int));
    rec(N, M, Q, a, b, c, d, A, &res);
    printf("%d\n", res);
    free(A);
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    int *a = (int *)malloc(Q * sizeof(int));
    int *b = (int *)malloc(Q * sizeof(int));
    int *c = (int *)malloc(Q * sizeof(int));
    int *d = (int *)malloc(Q * sizeof(int));
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    solve(N, M, Q, a, b, c, d);
    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}

// End of Code.
