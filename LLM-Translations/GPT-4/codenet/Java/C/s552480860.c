#include <stdio.h>

int main() {
    int h1, m1, h2, m2, k;
    scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    printf("%d\n", t2 - t1 - k);

    return 0;
}
// 
