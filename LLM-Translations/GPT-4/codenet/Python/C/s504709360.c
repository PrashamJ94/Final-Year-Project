#include <stdio.h>
#include <string.h>

int main() {
    char s[27];
    scanf("%s", s);
    int len = strlen(s);
    if (len < 26) {
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (!strchr(s, c)) {
                printf("%s%c\n", s, c);
                return 0;
            }
        }
    } else {
        for (int i = 25; i > 0; i--) {
            if (s[i - 1] < s[i]) {
                s[i] = '\0';
                for (int j = 0; j < 26; j++) {
                    char c = 'a' + j;
                    if (c > s[i - 1] && !strchr(s, c)) {
                        printf("%.*s%c\n", i-1, s, c);
                        return 0;
                    }
                }
            }
        }
        printf("-1\n");
    }
    return 0;
}
// 
