
#include <stdio.h>
#include <stdint.h>

int main() {
    int N;
    scanf("%d", &N);

    int64_t A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    int64_t result = 0;
    for (int b = 0; b < 60; b++) {
        int bs = 0;
        for (int i = 0; i < N; i++) {
            bs += (A[i] >> b) & 1;
        }

        int64_t temp = bs * (N - bs) * (1LL << b);
        result = (result + temp) % 1000000007;
    }

    printf("%lld\n", result);
    return 0;
}

//End of Code
