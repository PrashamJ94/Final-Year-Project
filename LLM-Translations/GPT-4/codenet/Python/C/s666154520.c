#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 1; i < 10 * 10 * 10 * 10 * 10; i++) {
        if (i * i > n) {
            printf("%d", (i - 1) * (i - 1));
            return 0;
        }
    }
    return 0;
}
// 
