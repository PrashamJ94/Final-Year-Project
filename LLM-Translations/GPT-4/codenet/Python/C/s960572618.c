#include <stdio.h>
#include <string.h>

int main() {
    char a[10], b[10], c[10];
    scanf("%s %s %s", a, b, c);

    if (strcmp(a, b) == 0 && strcmp(b, c) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// 
