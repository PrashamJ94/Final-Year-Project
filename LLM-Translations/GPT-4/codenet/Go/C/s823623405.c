
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int pow_mod(int n, int k, int mod);
int add_mod(int a, int b, int mod);
int sub_mod(int a, int b, int mod);
int mul_mod(int a, int b, int mod);
int div_mod(int a, int b, int mod);
void primeFactorize(int n, int *factors);

int main() {
    int n, i, k, v, x, ans;
    scanf("%d", &n);
    int *as = malloc(n * sizeof(int));
    int factors[1000] = {0};
    int ps[1000] = {0};

    for (i = 0; i < n; i++) {
        scanf("%d", &as[i]);

        primeFactorize(as[i], factors);
        for (k = 2; k < 1000; k++) {
            v = factors[k];
            ps[k] = max(ps[k], v);
        }
    }

    x = 1;
    for (k = 2; k < 1000; k++) {
        v = ps[k];
        for (i = 1; i <= v; i++) {
            x = mul_mod(x, k, 1000000007);
        }
    }

    ans = 0;
    for (i = 0; i < n; i++) {
        ans = add_mod(ans, div_mod(x, as[i], 1000000007), 1000000007);
    }
    printf("%d\n", ans);

    free(as);
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

void primeFactorize(int n, int *factors) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            factors[i]++;
        }
    }
    if (n != 1) {
        factors[n]++;
    }
}

int pow_mod(int n, int k, int mod) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return pow_mod(n, k - 1, mod) * n % mod;
    } else {
        int t = pow_mod(n, k / 2, mod);
        return t * t % mod;
    }
}

int add_mod(int a, int b, int mod) {
    return (a + b) % mod;
}

int sub_mod(int a, int b, int mod) {
    return (a + mod - b) % mod;
}

int mul_mod(int a, int b, int mod) {
    return (a % mod * b % mod) % mod;
}

int div_mod(int a, int b, int mod) {
    return mul_mod(a, pow_mod(b, mod - 2, mod), mod);
}

// 
