#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    char result[100] = "";
    int i = 0;
    while(i < strlen(s)) {
        if(s[i] == '.') {
            strcat(result, "0");
        } else {
            i += 1;
            if(s[i] == '.') {
                strcat(result, "1");
            } else {
                strcat(result, "2");
            }
        }
        i += 1;
    }
    printf("%s", result);
    return 0;
} // End of Code
