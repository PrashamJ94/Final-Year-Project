#include <stdio.h>

int main() {
    int X, t;
    scanf("%d%d", &X, &t);

    if (X - t >= 0) {
        printf("%d\n", X - t);
    } else {
        printf("0\n");
    }

    return 0;
}

// 
