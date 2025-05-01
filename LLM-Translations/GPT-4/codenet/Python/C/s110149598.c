#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    scanf("%s %s", a, b);
    int comparison = strcmp(a, b);

    if (comparison < 0) {
        printf("<\n");
    } else if (comparison > 0) {
        printf(">\n");
    } else {
        printf("=\n");
    }

    return 0;
} // 
