#include <stdio.h>

int main() {
    int a, b, c = 0;
    scanf("%d %d", &a, &b);

    for(int i = 0; i < 2; i++) {
        if(a >= b) {
            c += a;
            a -= 1;
        } else {
            c += b;
            b -= 1;
        }
    }

    printf("%d", c);

    return 0;
}

// End of Code
