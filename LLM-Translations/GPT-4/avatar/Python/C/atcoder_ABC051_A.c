#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000], ch = ',';
    char replace_char = ' ';
    int i;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == ch)
            str[i] = replace_char;
    }

    printf("After replacing commas: %s", str);

    return 0;
}

// End of Code
