#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if (B < C) {
        printf("0\n");
    } else if (A * C < B) {
        printf("%d\n", C);
    } else {
        printf("%d\n", B / A);
    }

    return 0;
}


