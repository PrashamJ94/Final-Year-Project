#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a, b; scanf("%d %d", &a, &b);
    char bstr[10];
    sprintf(bstr, "%d", b);
    int num = a * pow(10, strlen(bstr)) + b;

    int i;
    for (i = 1; i <= 100100; i++)
    {
        if (i * i == num) break;
    }

    if (i > 100100) printf("No\n");
    else printf("Yes\n");

    return 0;
}
// 
