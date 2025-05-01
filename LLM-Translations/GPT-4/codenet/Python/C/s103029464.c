#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N], B[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        B[i] = 0;
    }

    for (int i = N - 1; i >= 0; i--) {
        int tmp_sum = 0;
        for (int j = (i + 1) * 2 - 1; j < N; j += i + 1) {
            tmp_sum += B[j];
            tmp_sum %= 2;
        }
        B[i] = tmp_sum ^ A[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += B[i];
    }
    printf("%d\n", sum);

    for (int i = 0; i < N; i++) {
        if (B[i] == 1) {
            printf("%d ", i + 1);
        }
    }

    return 0;
}


