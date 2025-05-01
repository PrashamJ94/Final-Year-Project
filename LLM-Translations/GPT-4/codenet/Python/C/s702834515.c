#include <stdio.h>

int main()
{
    int n, r = 0;
    scanf("%d", &n);

    for(int ii = 0; ii < n; ii++)
    {
        if ((ii + 1) % 3 != 0 && (ii + 1) % 5 != 0)
        {
            r += (ii + 1);
        }
    }
    
    printf("%d\n", r);
    return 0;
}
// 
