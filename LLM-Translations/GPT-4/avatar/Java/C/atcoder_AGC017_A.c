#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t C(int n, int m) {
    mpz_t res;
    mpz_init_set_ui(res, 1);
    
    for (int i = m - n + 1; i <= m; i++) {
        mpz_mul_ui(res, res, i);
    }
    for (int i = 1; i <= n; i++) {
        mpz_div_ui(res, res, i);
    }
    
    return res;
}

int main() {
    int n, p, k0 = 0, k1 = 0;
    scanf("%d %d", &n, &p);
    
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 1) {
            k1++;
        } else {
            k0++;
        }
    }

    mpz_t ans;
    mpz_init_set_ui(ans, 1);

    for (int i = 0; i < k0; i++) {
        mpz_mul_ui(ans, ans, 2);
    }

    if (p == 0) {
        mpz_t add;
        mpz_init_set_ui(add, 0);
        
        for (int i = 0; i <= k1; i += 2) {
            mpz_add(add, add, C(i, k1));
        }
        mpz_mul(ans, ans, add);
        mpz_out_str(stdout, 10, ans);
        printf("\n");
    } else {
        mpz_t add;
        mpz_init_set_ui(add, 0);
        
        for (int i = 1; i <= k1; i += 2) {
            mpz_add(add, add, C(i, k1));
        }
        mpz_mul(ans, ans, add);
        mpz_out_str(stdout, 10, ans);
        printf("\n");
    }
    
    return 0;
}

// //End of Code
