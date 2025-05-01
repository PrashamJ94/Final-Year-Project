#include <stdio.h>

int main() {
    int q, h, s, d, n;
    scanf("%d %d %d %d", &q, &h, &s, &d);
    scanf("%d", &n);

    int min_1 = q * 4 < h * 2 ? q * 4 : h * 2;
    min_1 = min_1 < q * 2 + h ? min_1 : q * 2 + h;
    min_1 = min_1 < s ? min_1 : s;

    int min_2 = min_1 * 2 < d ? min_1 * 2 : d;

    printf("%d\n", (n % 2) * min_1 + (n / 2) * min_2);

    return 0;
}

// 
