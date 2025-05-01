#include <stdio.h>

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    int m = 998244353;
    int d[C + 1][D + 1];
    for(int i = 0; i <= C; i++) {
        for(int j = 0; j <= D; j++) {
            d[i][j] = 0;
        }
    }
    d[A][B] = 1;
    for(int i = A; i <= C; i++) {
        for(int j = B; j <= D; j++) {
            d[i][j] = (d[i][j] + ((d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m)) % m;
        }
    }
    printf("%d", d[C][D]);
    return 0;
}
//End of Code
