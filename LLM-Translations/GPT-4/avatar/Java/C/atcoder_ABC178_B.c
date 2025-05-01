#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

long modPower(long x, long y, long mod)
{
    long res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main()
{
    long a[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%ld", &a[i]);
    }
    printf("%ld\n", fmax(a[0] * a[2], fmax(a[1] * a[3], fmax(a[0] * a[3], a[1] * a[2]))));

    return 0;
}

// //End of Code
