#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    // A + B
    int x = a + b;
    // A - B
    int y = a - b;
    // A * B
    int z = a * b;

    int max = x;
    if (y > max) {
        max = y;
    }
    if (z > max) {
        max = z;
    }
    printf("%d\n", max);

    return 0;
}
// 
