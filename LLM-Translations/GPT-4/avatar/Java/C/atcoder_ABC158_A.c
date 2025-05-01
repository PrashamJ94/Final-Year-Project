#include <stdio.h>
#include <string.h>

int main() {
    char s[4];
    scanf("%s", s);

    if (strchr(s, 'A') && strchr(s, 'B')) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// //End of Code
