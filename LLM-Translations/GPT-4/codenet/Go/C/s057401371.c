#include <stdio.h>
#include <ctype.h>

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);

    int d = 'a' - 'A';
    for (int i = 0; s[i] != '\0'; i++) {
        char rr = s[i];
        if ('A' <= s[i] && s[i] <= 'Z') {
            rr = s[i] + d;
        } else if ('a' <= s[i] && s[i] <= 'z') {
            rr = s[i] - d;
        }
        printf("%c", rr);
    }
    printf("\n");

    return 0;
}

// 
