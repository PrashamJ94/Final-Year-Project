
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define MOD 1000000007
#define Int int64_t
#define rep(i,a,n) for(Int (i)=(a); (i)<(n); (i)++)

Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

int main() {
    Int a, b, c, n, m, k, x, y = 0, ans = 0;
    scanf("%lld %lld %lld", &k, &a, &b);
    for (int i = a; i <= b; ++i) {
        if (i % k == 0) {
            printf("OK\n");
            return 0;
        }
    }
    printf("NG\n");

    return 0;
}


