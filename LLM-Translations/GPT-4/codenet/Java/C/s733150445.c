#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main() {
    char a_str[1024], b_str[1024];
    mpz_t a, b, mul;

    scanf("%s %s", a_str, b_str);

    mpz_init_set_str(a, a_str, 10);
    mpz_init_set_str(b, b_str, 10);
    mpz_init(mul);

    mpz_mul(mul, a, b);
    gmp_printf("%Zd\n", mul);

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(mul);

    return 0;
}
// 
