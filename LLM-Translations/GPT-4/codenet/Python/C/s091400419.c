#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int sum = a + b;
    int difference = a - b;
    int product = a * b;

    int max_result = sum;

    if (difference > max_result) {
        max_result = difference;
    }

    if (product > max_result) {
        max_result = product;
    }

    printf("%d\n", max_result);

    return 0;
}
// 
