#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int total = 0;

    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        for (int j = i + 1; j < strlen(s); j++) {
            if (s[i] == s[j]) {
                total++;
            }
        }
    }

    printf(total == 2 ? "Yes\n" : "No\n");

    return 0;
}
// 
