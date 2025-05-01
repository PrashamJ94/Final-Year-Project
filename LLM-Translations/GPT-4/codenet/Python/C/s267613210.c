#include <stdio.h>

int main() {
    int K, N, i;
    scanf("%d %d", &K, &N);
    int A[N], dist[N];

    for(i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for(i = 0; i < N - 1; i++) {
        dist[i] = A[i + 1] - A[i];
    }

    dist[N - 1] = K + A[0] - A[N - 1];
    int maxv = dist[0];
    int sum = 0;

    for(i = 0; i < N; i++) {
        sum += dist[i];
        if(dist[i] > maxv) {
            maxv = dist[i];
        }
    }

    printf("%d\n", sum - maxv);
    return 0;
}
// 
