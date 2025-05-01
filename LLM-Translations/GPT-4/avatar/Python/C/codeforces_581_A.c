#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int min = a < b ? a : b;
    printf("%d ", min);

    int max = a > b ? a : b;
    printf("%d\n", (max - min) / 2);

    return 0;
} // End of Code
