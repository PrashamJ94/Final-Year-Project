#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int max(int x[], int len) {
    int res = x[0];
    for (int i = 1; i < len; i++) {
        res = fmax(x[i], res);
    }
    return res;
}

int min(int x[], int len) {
    int res = x[0];
    for (int i = 1; i < len; i++) {
        res = fmin(x[i], res);
    }
    return res;
}

int pow_int(int x, int y) {
    return (int)pow(x, y);
}

int abs_int(int x) {
    return abs(x);
}

int main() {
    int N, M, ans;
    scanf("%d %d", &N, &M);
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    printf("%d\n", ans);
    return 0;
}

/*  */
