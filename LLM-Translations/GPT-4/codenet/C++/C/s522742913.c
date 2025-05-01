#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char source[11];
    scanf("%s", source);

    int len = strlen(source);
    if(len > 10 || len < 1)
    {
        return -1;
    }

    int max_i = (int)(pow(2, len - 1));

    double sum = 0;

    for (int i = 0; i < max_i; ++i)
    {
        int plus = i;

        double number = 0;

        char working[11];
        strcpy(working, source);
        while(plus)
        {
            int index = 0;
            while(!(plus & (1 << index))) ++index;
            char temp[11];
            strncpy(temp, working, index + 1);
            temp[index + 1] = '\0';
            sum += atof(temp);
            plus >>= index + 1;
            memmove(working, working + index + 1, strlen(working) - index);
        }
        sum += atof(working);
    }

    printf("%.0lf\n", sum);

    return 0;
}
/*  */
