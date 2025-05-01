#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", (k % n == 0) ? (n + k) : (k - n));
    return 0;
}
// 
