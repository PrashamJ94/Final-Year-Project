
#include <stdio.h>

int subtract(int a, int b) {
    int total = 0;
    if (a > b) {
        while (a > 0 && b > 0) {
            total += a / b;
            a = a % b;
            if (a > 0) {
                total += b / a;
                b = b % a;
            }
        }
        return total;
    }
    if (a < b) {
        while (a > 0 && b > 0) {
            total += b / a;
            b = b % a;
            if (b > 0) {
                total += a / b;
                a = a % b;
            }
        }
        return total;
    }
    if (a == b) {
        return 1;
    }
    return 0;
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    int lst[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        lst[i] = subtract(a, b);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", lst[i]);
    }
    return 0;
}
/* End of Code */

//Please note that the Python code you provided doesn't perform a simple subtraction operation. The translated C code also follows the same logic and may not provide expected results for subtraction.
