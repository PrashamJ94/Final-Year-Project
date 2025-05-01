#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long number, ans = -1, value = 0;
    int mask = 2;

    scanf("%ld", &number);

    while (value < number) {
        int zeros = 0;
        char s[64];
        _itoa(mask++, s, 2);
        s[strlen(s) - 1] = '\0';

        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') {
                zeros++;
            }
        }

        if (zeros != strlen(s) - zeros) {
            continue;
        }

        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '0') {
                s[i] = '4';
            } else {
                s[i] = '7';
            }
        }

        value = atol(s);
    }

    printf("%ld\n", value);

    return 0;
}
// //End of Code
