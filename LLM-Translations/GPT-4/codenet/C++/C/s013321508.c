#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int L[100000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    qsort(L, N, sizeof(int), compare);

    for (int i = 0; i < M; i++) {
        int max_L = L[0];
        if (max_L == 0) {
            break;
        }

        max_L /= 2;
        L[0] = max_L;
        qsort(L, N, sizeof(int), compare);
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += L[i];
    }

    printf("%lld\n", ans);

    return 0;
}
// 
