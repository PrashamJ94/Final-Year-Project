#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[2][101];
    int a, b;
    char u[101];

    scanf("%s %s", str[0], str[1]);
    scanf("%d %d", &a, &b);
    scanf("%s", u);

    printf("%d %d\n", strcmp(u, str[0]) == 0 ? a - 1 : a, strcmp(u, str[0]) == 0 ? b : b - 1);

    return 0;
} // //End of Code
