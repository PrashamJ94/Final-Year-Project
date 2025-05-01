#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    int ve[n / 2];
    int vo[n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        ve[i] = v[2 * i];
        vo[i] = v[2 * i + 1];
    }
    qsort(ve, n / 2, sizeof(int), cmp);
    qsort(vo, n / 2, sizeof(int), cmp);

    int ce[100001] = {0};
    int co[100001] = {0};
    for (int i = 0; i < n / 2; i++)
    {
        ce[ve[i]]++;
        co[vo[i]]++;
    }
    int max_ce = 0;
    int max_ce_idx = 0;
    int max_co = 0;
    int max_co_idx = 0;
    for (int i = 0; i < 100001; i++)
    {
        if (ce[i] > max_ce)
        {
            max_ce = ce[i];
            max_ce_idx = i;
        }
        if (co[i] > max_co)
        {
            max_co = co[i];
            max_co_idx = i;
        }
    }

    int ans = n;
    if (max_ce_idx != max_co_idx)
    {
        ans = n - max_ce - max_co;
    }
    else
    {
        int max_ce_2 = 0;
        int max_co_2 = 0;
        for (int i = 0; i < 100001; i++)
        {
            if (i == max_ce_idx)
                continue;
            if (ce[i] > max_ce_2)
            {
                max_ce_2 = ce[i];
            }
            if (co[i] > max_co_2)
            {
                max_co_2 = co[i];
            }
        }
        ans = n - max_ce - max_co_2;
        if (ans > n - max_ce_2 - max_co)
        {
            ans = n - max_ce_2 - max_co;
        }
    }
    printf("%d\n", ans);

    return 0;
}
// 
