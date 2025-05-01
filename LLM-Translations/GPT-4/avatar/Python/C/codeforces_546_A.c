#include <stdio.h>

int main() {
    int k, n, w, total = 0, i;
    scanf("%d %d %d", &k, &n, &w);
    if (1 <= k && w <= 1000) {
        for (i = 1; i <= w; i++) {
            total += i * k;
        }
        if (total > n) {
            printf("%d", total - n);
        } else {
            printf("0");
        }
    }
    return 0;
} // End of Code
