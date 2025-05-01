#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int x, i;
    double sqrtNum;
    scanf("%d", &x);

    if (x != 2 && x % 2 == 0) {
        x++;
    }

    while (true) {
        sqrtNum = sqrt(x);
        for (i = 3; i <= sqrtNum; i += 2) {
            if (x % i == 0) {
                break;
            }
        }
        if (i > sqrtNum) {
            break;
        }
        x += 2;
    }

    printf("%d\n", x);
    return 0;
} // //End of Code.
