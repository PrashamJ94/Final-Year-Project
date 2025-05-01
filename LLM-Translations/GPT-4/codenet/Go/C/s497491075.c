
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N, D, count = 0;
    scanf("%d %d", &N, &D);

    int x, y;
    double d;

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        d = sqrt(x * x + y * y);
        if (D >= d) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}


