#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_NUM 26

int main() {
    int memo[ALPHABET_NUM] = {0};
    char str[1024];

    while (fgets(str, sizeof(str), stdin)) {
        int len = strlen(str);
        if (len == 0) {
            break;
        }
        for (int i = 0; i < len; i++) {
            char c = str[i];

            if ('a' <= c && c <= 'z') {
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                memo[c - 'A']++;
            } else {
                continue;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        printf("%c : %d\n", (char) (i + 'a'), memo[i]);
    }

    return 0;
}

// 
