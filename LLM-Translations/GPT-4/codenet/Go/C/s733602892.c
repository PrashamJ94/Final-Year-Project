#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b) - (*(int *)a);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int As[N], Fs[N], scores[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &As[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &Fs[i]);
    }

    qsort(As, N, sizeof(int), compare);
    qsort(Fs, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }

    qsort(scores, N, sizeof(int), compare);

    int ok = scores[0], ng = -1;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        int isOK = 1;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = 0;
            }
        }

        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    printf("%d\n", ok);
    return 0;
}
// 
