#include <stdio.h>

int main() {
    int X, h, a, y;
    scanf("%d", &X);
    h = X / 500;
    a = (X % 500) / 5;
    y = h * 1000 + a * 5;
    printf("%d\n", y);
    return 0;
} // 
