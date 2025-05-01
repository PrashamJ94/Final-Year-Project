
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int64_t combi(int n, int k);
int64_t pow64(int64_t base, unsigned int exponent);

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int64_t total = 0;
    for (int i = k; i <= n + 1; i++) {
        total += combi(n, i);
        total = total % (pow64(10, 9) + 7);
    }
    printf("%lld\n", total);
    return 0;
}

int64_t combi(int n, int k) {
    int64_t min = (int64_t)(k - 1) * (int64_t)k / 2;
    int64_t max = (int64_t)(2 * n - k + 1) * (int64_t)k / 2;
    return max - min + 1;
}

int64_t pow64(int64_t base, unsigned int exponent) {
    int64_t answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}


