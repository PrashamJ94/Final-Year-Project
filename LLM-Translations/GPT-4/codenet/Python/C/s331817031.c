//c
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);

    char l[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            scanf(" %c", &l[i][j]);
        }
    }

    int tmp = 0;
    bool possible = true;

    for (int i = 0; i < h && possible; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (l[i][j] == '#')
            {
                if (j < tmp)
                {
                    printf("Impossible\n");
                    possible = false;
                    break;
                }
                else
                {
                    tmp = j;
                }
            }
        }
    }

    if (possible)
    {
        printf("Possible\n");
    }

    return 0;
}
// 


