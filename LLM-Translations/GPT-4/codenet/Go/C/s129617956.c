#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int min(int i, int j) {
    if (i > j) {
        return j;
    }
    return i;
}

int main() {
    int n, rt, minf = 100, ndigit, b;
    scanf("%d", &n);
    rt = (int)sqrt((double)n);
    for (int i = 1; i < rt + 1; i++) {
        if (n % i == 0) {
            b = n / i;
            ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            minf = min(minf, ndigit);
        }
    }
    printf("%d\n", minf);
    return 0;
}

// 
