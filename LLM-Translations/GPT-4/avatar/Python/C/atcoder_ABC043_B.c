#include <stdio.h>
#include <string.h>

int main() {
    char s[100], my_str[100] = "";
    printf("Enter a string: ");
    scanf("%s", s);

    int len = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '0' || s[i] == '1') {
            my_str[len] = s[i];
            len++;
        }
        else if(s[i] == 'B' && len != 0) {
            my_str[len-1] = '\0';
            len--;
        }
    }
    printf("%s", my_str);
    return 0;
} // End of Code
