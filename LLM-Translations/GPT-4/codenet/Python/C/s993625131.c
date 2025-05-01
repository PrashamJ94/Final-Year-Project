#include <stdio.h>
#include <string.h>

int main()
{
    char S[1000];
    scanf("%s", S);

    int count = 0;
    int record = 0;
    for (int i = 0; i < strlen(S); i++)
    {
        if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T')
        {
            count += 1;
        }
        else
        {
            if (count > record)
            {
                record = count;
            }
            count = 0;
        }
    }
    if (count > record)
    {
        record = count;
    }

    printf("%d\n", record);

    return 0;
}
// 
