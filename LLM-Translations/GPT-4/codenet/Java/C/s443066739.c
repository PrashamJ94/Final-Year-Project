#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long pre[n+1];
    pre[0] = 0;

    for(int i=1; i<=n; i++)
    {
        long long val;
        scanf("%lld", &val);
        pre[i] = pre[i - 1] + val;
    }

    long long min = LLONG_MAX;

    for(int i=1; i<n; i++)
    {
        long long val1 = pre[i], val2 = pre[n] - pre[i];
        long long diff = llabs(val1 - val2);
        if(diff < min)
        {
            min = diff;
        }
    }

    printf("%lld\n", min);
    
    return 0;
}
// 
