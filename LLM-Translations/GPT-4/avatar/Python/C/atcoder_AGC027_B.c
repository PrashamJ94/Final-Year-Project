#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X, i, j, k;
    long long *A, *S, E, ans;

    scanf("%d %d", &N, &X);
    A = malloc(N * sizeof(long long));
    S = malloc(N * sizeof(long long));

    for (i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        S[i] = i == 0 ? A[i] : S[i - 1] + A[i];
    }

    ans = 1LL << 60;
    for (k = 1; k <= N; k++) {
        E = (long long)k * X;
        for (j = N - 1; j >= 0; j -= k) {
            E += 2 * S[j];
        }
        ans = ans < E ? ans : E;
    }

    printf("%lld\n", ans + (long long)N * X + 5 * S[N - 1]);

    free(A);
    free(S);

    return 0;
}
/* End of Code */

