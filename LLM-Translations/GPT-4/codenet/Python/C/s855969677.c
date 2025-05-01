
#include <stdio.h>
#include <string.h>

int main() {
    char s[4];
    scanf("%s", s);

    if (strcmp(s, "RRR") == 0) {
        printf("%d\n", 3);
    } else if (strcmp(s, "SSS") == 0) {
        printf("%d\n", 0);
    } else if (strcmp(s, "RRS") == 0 || strcmp(s, "SRR") == 0) {
        printf("%d\n", 2);
    } else {
        printf("%d\n", 1);
    }

    return 0;
}


