#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int max_value = 10 * A + B + C;
    if (10 * B + C + A > max_value) {
        max_value = 10 * B + C + A;
    }
    if (10 * C + A + B > max_value) {
        max_value = 10 * C + A + B;
    }

    printf("%d\n", max_value);

    return 0;
}


