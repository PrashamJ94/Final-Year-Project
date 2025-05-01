#include <stdio.h>
#include <math.h>

int main() {
    int a, b, digit;
    while (scanf("%d %d", &a, &b) != EOF) {
        digit = (int) log10(a + b) + 1;
        printf("%d\n", digit);
    }
    return 0;
}
/*  */
