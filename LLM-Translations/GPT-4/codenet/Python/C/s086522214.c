#include <stdio.h>
#include <stdlib.h>

int main()
{
    char S[11];
    scanf("%s", S);

    char month[3], day[3];
    for (int i = 0; i < 2; i++)
    {
        month[i] = S[i + 5];
        day[i] = S[i + 8];
    }
    month[2] = '\0';
    day[2] = '\0';

    int date = atoi(month) * 100 + atoi(day);
    if (date <= 430)
    {
        printf("Heisei\n");
    }
    else
    {
        printf("TBD\n");
    }

    return 0;
}
