#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double input, countOdd;
    long double result;

    if (scanf("%lf", &input) != 1) {
        fprintf(stderr, "Error reading input\n");
        exit(0);
    }

    countOdd = round(input / 2);
    result = countOdd / input;

    printf("%.10Lf\n", result);

    return 0;
}

// //End of Code
