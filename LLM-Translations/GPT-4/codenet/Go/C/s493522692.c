#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//Util
int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

int minInt(int a, int b) {
    return (a < b) ? a : b;
}

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int tmp = minInt(N, M / 2);
    int ans = 0;
    ans += tmp;
    N -= tmp;
    M -= tmp * 2;
    printf("%d\n", ans + M / 4);
    return 0;
}
// 
