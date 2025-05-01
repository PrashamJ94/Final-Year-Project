#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int k;
    int l = 0;

    // Input string
    printf("Enter string: ");
    scanf("%s", s);

    // Input integer
    printf("Enter integer: ");
    scanf("%d", &k);

    // Loop through string
    for (int i = 0; i < strlen(s); i++) {
        if(s[i] != '1') {
            break;
        }
        l++;
    }

    if(l >= k) {
        printf("%d\n", 1);
    } else {
        printf("%c\n", s[l]);
    }

    return 0;
}

