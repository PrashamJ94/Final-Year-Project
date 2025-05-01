#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main() {
    int n, m, k;
    mpz_t gcd, temp;
    mpz_init(gcd);
    mpz_init(temp);

    scanf("%d %d", &n, &m);
    mpz_gcd_ui(gcd, gcd, n);
    mpz_gcd_ui(gcd, gcd, m);

    char s[n+1], t[m+1];
    scanf("%s %s", s, t);

    long long result = -1;
    for (k = 0; k < mpz_get_ui(gcd); k++) {
        if (s[k * n / mpz_get_ui(gcd)] != t[k * m / mpz_get_ui(gcd)]) {
            result = -1;
            break;
        }
        mpz_mul_ui(temp, temp, n);
        mpz_mul_ui(temp, temp, m);
        mpz_divexact(temp, temp, gcd);
        result = mpz_get_ui(temp);
    }

    printf("%lld\n", result);

    mpz_clear(gcd);
    mpz_clear(temp);

    return 0;
} // //End of Code
