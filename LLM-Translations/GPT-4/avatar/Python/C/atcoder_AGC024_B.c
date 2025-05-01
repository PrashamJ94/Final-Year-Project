#include <stdio.h>

void editorial(int N, int* P) {
    if (N == 1) {
        printf("0\n");
        return;
    }
    int a[N + 1];
    for (int i = 0; i < N + 1; i++) a[i] = 0;
    for (int i = 0; i < N; i++) {
        a[P[i]] = i;
    }
    int tmp = 1;
    int max_len = 1;
    for (int i = 1; i < N; i++) {
        if (a[i] < a[i + 1]) {
            tmp += 1;
            max_len = (max_len > tmp) ? max_len : tmp;
        } else {
            tmp = 1;
        }
    }
    int ans = N - max_len;
    printf("%d\n", ans);
}

int main() {
    int N;
    scanf("%d", &N);
    int P[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }
    editorial(N, P);
    return 0;
}

// End of Code
