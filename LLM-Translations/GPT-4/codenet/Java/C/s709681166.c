#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);

    for(int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if(isupper(c)) {
            c += 32;
            printf("%c", c);
        } else if(islower(c)) {
            c -= 32;
            printf("%c", c);
        } else {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
// 
