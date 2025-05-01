#include <stdio.h>
#include <math.h>

int main() {
    int x;
    scanf("%d", &x);
    printf("%d", 360 / gcd(360, x));
    return 0;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// End of Code
