#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%s\n", a % 500 <= b ? "Yes" : "No");
    return 0;
}
/*  */
