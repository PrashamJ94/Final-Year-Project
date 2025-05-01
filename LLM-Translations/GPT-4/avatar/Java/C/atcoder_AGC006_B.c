#include <stdio.h>

int main() {
    int n, x, max;
    scanf("%d", &n);
    scanf("%d", &x);

    max = n * 2 - 1;

    if (x == 1 || x == max) {
        printf("No\n");
        return 0;
    }

    printf("Yes\n");

    for (int i = x + n - 1; i < x + n + max - 1; i++) {
        printf("%d\n", i % max + 1);
    }

    return 0;
}

// //End of Code.
