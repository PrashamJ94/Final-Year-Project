#include <stdio.h>
#include <string.h>

int main() {
    char s[101], t[101];
    scanf("%s", s);
    scanf("%s", t);

    if (strncmp(s, t, strlen(t) - 1) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
} // 
