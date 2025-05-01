#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000], res[1000];
    int i, j = 0;
    char punctuation[] = ",.!?";

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    for (i = 0; i < strlen(s); i++) {
        if (i >= 1) {
            if (s[i] == ' ') {
                if (res[j - 1] != ' ') {
                    res[j++] = s[i];
                } else {
                    continue;
                }
            } else {
                if (strchr(punctuation, s[i])) {
                    if (res[j - 1] == ' ') {
                        j--;
                    }
                    res[j++] = s[i];
                    res[j++] = ' ';
                } else {
                    res[j++] = s[i];
                }
            }
        } else {
            if (s[i] == ' ') {
                continue;
            }
            if (strchr(punctuation, s[i])) {
                continue;
            } else {
                res[j++] = s[i];
            }
        }
    }

    res[j] = '\0';
    printf("Result: %s\n", res);

    return 0;
}
// End of Code
