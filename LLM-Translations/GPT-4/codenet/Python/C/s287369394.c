#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N+1], B[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    A[N] = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int d = A[i] < B[i] ? A[i] : B[i];
        ans += d;
        A[i] -= d;
        B[i] -= d;
        d = A[i + 1] < B[i] ? A[i + 1] : B[i];
        ans += d;
        A[i + 1] -= d;
        B[i] -= d;
    }

    printf("%d\n", ans);

    return 0;
}
// 
