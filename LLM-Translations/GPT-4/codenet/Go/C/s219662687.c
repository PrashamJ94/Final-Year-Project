#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int abs(int x) {
    return abs(x);
}

int min(int x, int y) {
    return (x < y) ? x : y;
}

int main() {
    int INF = (int) pow(10, 11);
    int A, B, Q;
    scanf("%d %d %d", &A, &B, &Q);
    int s[A+2], t[B+2];
    s[0] = -INF;
    s[A+1] = INF;
    for (int i = 1; i <= A; i++) {
        scanf("%d", &s[i]);
    }

    t[0] = -INF;
    t[B+1] = INF;
    for (int i = 1; i <= B; i++) {
        scanf("%d", &t[i]);
    }

    for (int i = 0; i < Q; i++) {
        int x;
        scanf("%d", &x);
        int *b = upper_bound(s, s + A + 2, x, cmp);
        int *d = upper_bound(t, t + B + 2, x, cmp);
        int res = INF;
        int S[2] = {*(b - 1), *b};
        int T[2] = {*(d - 1), *d};
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int d1 = abs(S[j] - x) + abs(T[k] - S[j]);
                int d2 = abs(T[k] - x) + abs(S[j] - T[k]);
                res = min(res, min(d1, d2));
            }
        }
        printf("%d\n", res);
    }

    return 0;
}
// 
