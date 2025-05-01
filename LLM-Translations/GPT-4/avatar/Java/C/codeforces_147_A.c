#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isPunctuation(char c) {
    if (c == '.') return true;
    if (c == ',') return true;
    if (c == '!') return true;
    if (c == '?') return true;
    return false;
}

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    int n = strlen(s);

    char output[1000];
    int outputIndex = 0;
    output[outputIndex++] = s[0];

    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                output[outputIndex++] = ' ';
            }
            output[outputIndex++] = c;
        } else if (isPunctuation(c)) {
            output[outputIndex++] = c;
        }
    }
    output[outputIndex] = '\0';

    printf("%s\n", output);
    return 0;
}

// //End of Code
