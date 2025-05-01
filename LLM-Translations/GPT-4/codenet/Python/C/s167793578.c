#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int a = N * (N - 1) / 2;
    int b = M * (M - 1) / 2;

    printf("%d\n", a + b);

    return 0;
} // 
