#include <stdio.h>

int main() {
    int a, b, c, k;
    scanf("%d %d %d %d", &a, &b, &c, &k);

    if (k % 2 == 0) {
        printf("%d\n", a - b);
    } else {
        printf("%d\n", b - a);
    }

    return 0;
} // 
