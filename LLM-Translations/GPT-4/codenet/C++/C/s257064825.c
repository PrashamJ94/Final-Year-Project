#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

int main()
{
    char str[1000];
    scanf("%s", str);
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        sum += (str[i] - '0');
    }
    if (sum % 9 == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
// 
