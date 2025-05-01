
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, square, loop, div, i, j;
    scanf("%d", &n);
    square = n * n;
    int odd[square], even[square];
    int p_odd = 0, p_even = 0;

    for (i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even[p_even++] = i;
        } else {
            odd[p_odd++] = i;
        }
    }

    loop = square / n;
    div = loop / 2;

    for (i = 1; i <= loop; i++) {
        for (j = 0; j < div; j++) {
            if (i % 2 == 1) {
                printf("%d %d ", odd[0], even[p_even - 1]);
                p_odd--;
                p_even--;
            } else {
                printf("%d %d ", even[0], odd[p_odd - 1]);
                p_even--;
                p_odd--;
            }
        }
        printf("\n");
    }

    return 0;
} // //End of Code

I've translated the code to C to the best of my knowledge. However, please note that C does not support dynamic lists like Java, so the items are not being removed from the arrays, but the pointers are being moved to simulate removal. Also, the `debug` function in the original Java code was not translated because C does not have a native method for printing arrays.
