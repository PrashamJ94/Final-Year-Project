#include <math.h>
#include <stdio.h>

int main() {
    int n, x = 1;
    scanf("%d", &n);
    while ( fmod(log2(n), 1) != 0 ) {
        x += 1;
        n -= pow(2, (int) log2(n));
    }
    printf("%d", x);
    return 0;
} // End of Code

