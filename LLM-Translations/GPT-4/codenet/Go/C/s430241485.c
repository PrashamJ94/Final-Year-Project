#include <stdio.h>
#include <string.h>

int main() {
    char s[100], t[100];
    scanf("%s %s", s, t);
    strcat(t, s);
    printf("%s\n", t);
    return 0;
}
// 
