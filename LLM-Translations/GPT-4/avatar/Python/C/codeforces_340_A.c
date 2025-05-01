#include <stdio.h>

int gcd(int a, int b) {
    while (a % b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int x, y, a, b;
    scanf("%d%d%d%d", &x, &y, &a, &b);
    int lcmValue = lcm(x, y);
    printf("%d\n", b / lcmValue - (a - 1) / lcmValue);
    return 0;
} // End of Code
