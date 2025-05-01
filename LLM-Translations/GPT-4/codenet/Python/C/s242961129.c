#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i;
    scanf("%d", &N);
    int A[N+2];
    for(i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    A[0] = A[N+1] = 0;
    
    int ans = abs(A[N+1]);
    int diff[N];
    for(i = 1; i <= N; i++) {
        int dif = abs(A[i] - A[i-1]) + abs(A[i] - A[i+1]) - abs(A[i-1] - A[i+1]);
        ans += abs(A[i] - A[i-1]);
        diff[i-1] = dif;
    }

    for(i = 0; i < N; i++) {
        printf("%d\n", ans - diff[i]);
    }

    return 0;
}

