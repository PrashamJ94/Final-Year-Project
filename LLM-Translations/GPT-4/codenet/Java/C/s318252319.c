#include <stdio.h>
#include <string.h>

int main()
{
    char s[10];
    scanf("%s", s);
    int n = s[strlen(s) - 1] - '0';
    
    if (n == 3)
        printf("bon\n");
    else if (n == 0 || n == 1 || n == 6 || n == 8)
        printf("pon\n");
    else
        printf("hon\n");

    return 0;
}
// 
