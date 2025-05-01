
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_even_string(char *s, int length);

int main() {

    char S[1024];
    fgets(S, sizeof(S), stdin);
    int length = strlen(S) - 1;
    S[length] = '\0';

    if (length % 2 == 1) {
        length -= 1;
    } else {
        length -= 2;
    }

    for (; length > 0; length -= 2) {
        if (is_even_string(S, length)) {
            break;
        }
    }
    printf("%d\n", length);
    return 0;
}

bool is_even_string(char *s, int length) {
    int half_length = length / 2;
    for (int i = 0; i < half_length; i++) {
        if (s[i] != s[half_length + i]) {
            return false;
        }
    }
    return true;
}

//
