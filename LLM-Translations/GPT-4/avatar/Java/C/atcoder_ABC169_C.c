#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    long a;
    double b;
    scanf("%ld %lf", &a, &b);

    int bInt = (int)(b * 100 + 0.5);
    long result = (a * bInt) / 100;

    printf("%ld\n", result);

    return 0;
}
// //End of Code
