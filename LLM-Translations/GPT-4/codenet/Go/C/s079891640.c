#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1001];
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        for (int j = i + 1; j < strlen(s); j++) {
            if (s[i] == s[j]) {
                printf("no\n");
                exit(0);
            }
        }
    }

    printf("yes\n");
    return 0;
}
// 
