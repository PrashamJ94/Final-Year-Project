#include <stdio.h>
#include <math.h>

int main() {
    int intA;

    // Read input from the user
    scanf("%d", &intA);

    // Calculate the cube of the input
    double dbAnswer = pow((double)intA, 3);
    int intAnswer = (int)dbAnswer;

    // Print the result
    printf("%d\n", intAnswer);

    return 0;
}

//
