#include <stdio.h>

int main() {
    long k, a, b;

    scanf("%ld %ld %ld", &k, &a, &b);

    if (b <= a + 2) {
        printf("%ld\n", 1 + k);
        return 0;
    }

    long x = k - (a - 1);
    long ans = a + (x / 2) * (b - a) + (x % 2);

    printf("%ld\n", ans);
    return 0;
}

// 
