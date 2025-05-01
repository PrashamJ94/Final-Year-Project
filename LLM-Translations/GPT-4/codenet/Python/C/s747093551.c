
#include <stdio.h>

int main() {
    int N, M, X, Y, i, max_x = -100, min_y = 101;
    scanf("%d %d %d %d", &N, &M, &X, &Y);

    int x[N], y[M];
    for (i = 0; i < N; i++) {
        scanf("%d", &x[i]);
        if (x[i] > max_x) {
            max_x = x[i];
        }
    }
    for (i = 0; i < M; i++) {
        scanf("%d", &y[i]);
        if (y[i] < min_y) {
            min_y = y[i];
        }
    }

    if (max_x < X) {
        max_x = X;
    }
    if (min_y > Y) {
        min_y = Y;
    }

    if (max_x < min_y) {
        printf("No War\n");
    } else {
        printf("War\n");
    }

    return 0;
}


