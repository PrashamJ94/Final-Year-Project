#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <gmp.h>

void run() {
    int W, H;
    while (true) {
        scanf("%d %d", &W, &H);
        if (W == 0 && H == 0) return;

        char map[H][W];
        for (int h = 0; h < H; h++) {
            scanf("%s", map[h]);
        }

        mpz_t dp[H][W];

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                mpz_t hprev;
                mpz_init_set_ui(hprev, 0);
                if (h >= 1) {
                    mpz_set(hprev, dp[h - 1][w]);
                }

                mpz_t wprev;
                mpz_init_set_ui(wprev, 0);
                if (w >= 1) {
                    mpz_set(wprev, dp[h][w - 1]);
                }

                if (isdigit(map[h][w])) {
                    mpz_t max;
                    mpz_init(max);
                    if (mpz_cmp(hprev, wprev) > 0) {
                        mpz_set(max, hprev);
                    } else {
                        mpz_set(max, wprev);
                    }
                    mpz_mul_ui(max, max, 10);
                    mpz_add_ui(dp[h][w], max, map[h][w] - '0');
                } else {
                    mpz_init_set_ui(dp[h][w], 0);
                }
            }
        }

        mpz_t max;
        mpz_init_set_ui(max, 0);
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (mpz_cmp(dp[h][w], max) > 0) {
                    mpz_set(max, dp[h][w]);
                }
            }
        }
        gmp_printf("%Zd\n", max);
    }
}

int main() {
    run();
    return 0;
}


//
