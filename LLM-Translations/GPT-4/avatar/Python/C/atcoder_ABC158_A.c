#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("Enter a string: ");
    fgets(s, 100, stdin);
    if (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
} // End of Code
