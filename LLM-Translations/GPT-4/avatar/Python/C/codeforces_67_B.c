#include <stdio.h>

int main()
{
    int n, k, p, l, m = 0;
    scanf("%d %d", &n, &k);
    int M[n];
    for (int i = 0; i < n; i++) scanf("%d", &M[i]);

    for (int j = 0; j < n; j++)
    {
        for (p = 0; p < n; p++)
        {
            if (M[p] == 0)
            {
                printf("%d ", p + 1);
                break;
            }
        }
        for (l = 0; l < p + 1 - k; l++) M[l]--;
        M[p]--;
    }
    return 0;
}
/* End of Code */
