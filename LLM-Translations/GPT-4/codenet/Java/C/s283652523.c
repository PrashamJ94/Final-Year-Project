#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long int sum_mod(long long int a, long long int b) {
    return (a + b) % MOD;
}

long long int product_mod(long long int a, long long int b) {
    return (a * b) % MOD;
}

void solve(int N, int *A, long long int *ans) {
    long long int sum = A[N - 1];
    *ans = 0;
    for (int i = N - 2; i >= 0; i--) {
        *ans = sum_mod(*ans, product_mod(sum, A[i]));
        sum = sum_mod(sum, A[i]);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int *A = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    long long int ans;
    solve(N, A, &ans);

    printf("%lld\n", ans);

    free(A);

    return 0;
}
// 
