#include <stdio.h>

int main() {
    int N, X, min;
    scanf("%d %d", &N, &X);
    int m[N];
    scanf("%d", &m[0]);
    X -= m[0];
    min = m[0];
    for (int i = 1; i < N; i++) {
        scanf("%d", &m[i]);
        X -= m[i];
        if (m[i] < min) {
            min = m[i];
        }
    }
    printf("%d\n", N + X / min);

    return 0;
}
// 
