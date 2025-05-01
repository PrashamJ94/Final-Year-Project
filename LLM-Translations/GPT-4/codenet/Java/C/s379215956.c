#include <stdio.h>
#include <string.h>

int main() {
    char s[5];
    scanf("%s", s);

    int a = 0;

    if(s[0] == s[1]) a = 1;
    if(s[1] == s[2]) a = 1;
    if(s[2] == s[3]) a = 1;

    if (a == 1) {
        printf("Bad\n");
    } else {
        printf("Good\n");
    }

    return 0;
}
// 
