#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long x, r, newNumber = 0;
    int pow = 0, i;
    scanf("%ld", &x);

    int listSize = (int)log10(x) + 1;
    long *list = (long *)malloc(listSize * sizeof(long));

    while (x > 0) {
        r = x % 10;
        if (9 - r < r) {
            if (x / 10 == 0 && 9 - r == 0)
                list[pow] = r;
            else
                list[pow] = 9 - r;
        } else {
            list[pow] = r;
        }
        x = x / 10;
        pow++;
    }

    pow = 0;
    for (i = 0; i < listSize; i++) {
        newNumber = newNumber + list[i] * (long)pow(10, pow);
        pow++;
    }

    printf("%ld\n", newNumber);
    free(list);

    return 0;
}

// //End of Code.
