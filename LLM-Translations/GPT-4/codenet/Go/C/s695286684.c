#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    for (int i = 0; i < strlen(s) - 3; i++) {
        if (strncmp(s + i, "2017", 4) == 0) {
            strncpy(s + i, "2018", 4);
        }
    }

    printf("%s\n", s);
    return 0;
}
// 
