#include <stdio.h>
#include <string.h>

int main() {
    char s;
    scanf(" %c", &s);
    char alphabets[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < strlen(alphabets); i++) {
        if (alphabets[i] == s) {
            printf("%c\n", alphabets[i + 1]);
            break;
        }
    }
    return 0;
}
// 
