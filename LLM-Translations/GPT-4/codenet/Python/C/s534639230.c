#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N, i;
    scanf("%d", &N);

    int D[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &D[i]);
    }

    int mod = 998244353;

    if (D[0] != 0) {
        printf("0\n");
        return 0;
    }

    qsort(D, N, sizeof(int), compare);

    int cnt[N];
    for (i = 0; i < N; i++) {
        cnt[i] = 0;
    }

    for (i = 0; i < N; i++) {
        cnt[D[i]]++;
    }

    if (cnt[0] > 1) {
        printf("0\n");
        return 0;
    }

    long long res = 1;

    for (i = 1; i <= D[N - 1]; i++) {
        if (cnt[i - 1] == 1) {
            continue;
        }
        int j;
        for (j = 0; j < cnt[i]; j++) {
            res *= cnt[i - 1];
            res %= mod;
        }
    }

    printf("%lld\n", res);

    return 0;
}

// 
