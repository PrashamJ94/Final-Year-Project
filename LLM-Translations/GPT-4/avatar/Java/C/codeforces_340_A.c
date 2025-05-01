#include <stdio.h>
#include <stdbool.h>

int main() {
    long x, y, a, b;
    scanf("%ld %ld %ld %ld", &x, &y, &a, &b);

    long j = 2, i, x1 = 0, y1 = 0, c = 0;
    bool ans = true;

    c = (x > y) ? x : y;

    if (c > b) {
        printf("0\n");
        ans = false;
    }

    while (c % ((x < y) ? x : y) != 0 && ans) {
        if (x > y) {
            c = x * j;
            j++;
        } else {
            c = y * j;
            j++;
        }

        if (c > b) {
            printf("0\n");
            ans = false;
            break;
        }
    }

    if (ans) {
        long count = 0;
        i = a;
        for (i = a; i <= b; i++) {
            if (i % c == 0) break;
        }

        if (i != b + 1) {
            printf("%ld", ((b - i) / c) + 1);
        } else {
            printf("0");
        }
    }

    return 0;
}

// //End of Code
