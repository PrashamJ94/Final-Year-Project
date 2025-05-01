#include <stdio.h>

int main() {
    int r;
    scanf("%d", &r);

    if (r < 1200) {
        printf("ABC\n");
        return 0;
    }

    if (r < 2800) {
        printf("ARC\n");
        return 0;
    }

    printf("AGC\n");

    return 0;
}
/*  */
