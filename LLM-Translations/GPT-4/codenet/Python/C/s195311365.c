#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    if(strlen(s) == 2) {
        printf("%s\n", s);
    } else {
        int length = strlen(s);
        for(int i = length - 1; i >= 0; i--) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}
// 
