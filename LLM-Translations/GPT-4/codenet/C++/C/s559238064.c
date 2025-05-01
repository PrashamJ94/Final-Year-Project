#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = (1 ? 1e9 + 7 : 998244353);



int main()
{
    char z[100];
    ll a, i;
    scanf("%s", z);
    a = strlen(z);
    for (i = 0; i < a - 1; i++)
    {
        if (z[i] == z[i + 1])
        {
            printf("Bad\n");
            return 0;
        }
    }
    printf("Good\n");
    return 0;
}
// 
