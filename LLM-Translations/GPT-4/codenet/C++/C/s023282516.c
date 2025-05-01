#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse_str(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char S[100001];
    scanf("%s", S);

    char divide[4][10] = {"dream", "dreamer", "erase", "eraser"};

    reverse_str(S);
    for (int i = 0; i < 4; ++i) reverse_str(divide[i]);

    bool can = true;
    for (int i = 0; i < strlen(S);) {
        bool can2 = false;
        for (int j = 0; j < 4; ++j) {
            char *d = divide[j];
            if (strncmp(S + i, d, strlen(d)) == 0) {
                can2 = true;
                i += strlen(d);
            }
        }
        if (!can2) {
            can = false;
            break;
        }
    }

    if (can) printf("YES\n");
    else printf("NO\n");

    return 0;
}
// 
