
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Arithmetic
int max(int a, int b, int c) {
    int m = a;
    if (m < b) {
        m = b;
    }
    if (m < c) {
        m = c;
    }
    return m;
}

int min(int a, int b, int c) {
    int m = a;
    if (m > b) {
        m = b;
    }
    if (m > c) {
        m = c;
    }
    return m;
}

int abs(int x) {
    if (x > 0) {
        return x;
    }
    return -x;
}

int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int main() {
    int A, B, C, K;
    scanf("%d %d %d %d", &A, &B, &C, &K);
    int ma = max(A, B, C);
    int rest = 0;

    if (ma == A) {
        rest += B + C;
    } else if (ma == B) {
        rest += A + C;
    } else {
        rest += A + B;
    }

    for (int i = 1; i <= K; i++) {
        ma *= 2;
    }

    printf("%d\n", ma + rest);
    return 0;
}


