#include <stdio.h>
#include <gmp.h>

int main() {
    mpz_t a, b, c;
    mpz_init(a);
    mpz_init(b);
    mpz_init(c);

    while (gmp_scanf("%Zd %Zd", a, b) != EOF) {
        mpz_max(c, a, b);

        if (mpz_cmp(a, c) == 0 && mpz_cmp(b, c) != 0)
            printf("GREATER\n");
        else if (mpz_cmp(b, c) == 0 && mpz_cmp(a, c) != 0)
            printf("LESS\n");
        else
            printf("EQUAL\n");
    }

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);
    return 0;
}
// 
