
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);

    char c = 'a';

    for (int j = 0; j < 26; j++) {
        bool found = false;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == c) {
                found = true;
                break;
            }
        }
        if (found == false) {
            printf("%c\n", c);
            return 0;
        }
        c++;
    }

    printf("None\n");

    return 0;
}

// 
