
#include <stdio.h>

// Define a function to get maximum of four numbers
int max_of_four(int a, int b, int c, int d) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    if (d > max) {
        max = d;
    }
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int max_product = max_of_four(a * c, b * d, a * d, b * c);
    printf("%d\n", max_product);
    return 0;
}
// End of Code

//This C code reads four integers from the user, calculates the product of each pair in both orders, then finds and prints the maximum of these four products.
