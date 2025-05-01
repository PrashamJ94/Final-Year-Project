#include <stdio.h>
#include <string.h>

int main() {
    char n[6];
    scanf("%s", n);
    char *a[] = {"10", "100", "1000", "10000", "100000"};
    int new = 0;
    for (int i = 0; i < strlen(n); i++) {
        new += n[i] - '0';
    }
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(n, a[i]) == 0) {
            found = 1;
            break;
        }
    }
    if (found)
        printf("10\n");
    else
        printf("%d\n", new);
    return 0;
} // End of Code
