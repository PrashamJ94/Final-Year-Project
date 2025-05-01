#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n % 10 == 9 || n / 10 == 9) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

//
