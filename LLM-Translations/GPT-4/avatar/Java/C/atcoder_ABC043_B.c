
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unhappyHacking(char *s, char *result);

int main() {
    char s[1024];
    char result[1024] = "";
    scanf("%s", s);
    unhappyHacking(s, result);
    printf("%s\n", result);
    return 0;
}

void unhappyHacking(char *s, char *result) {
    int i;
    int len = strlen(s);
    int pos = 0;
    for (i = 0; i < len; i++) {
        switch (s[i]) {
            case '0':
                result[pos++] = '0';
                break;
            case '1':
                result[pos++] = '1';
                break;
            case 'B':
                if (pos > 0) pos--;
                break;
        }
    }
    result[pos] = '\0';
}


//End of Code.
