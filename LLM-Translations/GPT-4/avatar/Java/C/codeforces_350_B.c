#include <stdio.h>

int main()
{
    int n, i, x, s, ans = 0;
    scanf("%d", &n);
    int a[n+1], b[n+1], num[n+1];
    bool st[n+1];
    char ss[100], sb[100], sss[100];
    
    for(i=1; i<=n; i++)
        scanf("%d", &a[i]);
    
    for(i=1; i<=n; i++)
        scanf("%d", &b[i]);
    
    for(i=1; i<=n; i++)
        num[b[i]]++;
    
    for(i=1; i<=n; i++)
    {
        if(a[i] == 1)
        {
            st[i] = true;
            x = b[i];
            sprintf(sss, "%d", i);
            strrev(sss);
            sprintf(sb, " %s", sss);
            s = 1;
            while(!st[x] && num[x] == 1 && x != 0 && a[x] != 1)
            {
                sprintf(sss, "%d", x);
                strrev(sss);
                sprintf(sb, " %s", sss);
                st[x] = true;
                x = b[x];
                s++;
            }
            if(s > ans)
            {
                ans = s;
                strrev(sb);
                strcpy(ss, sb);
            }
        }
    }
    
    printf("%d\n", ans);
    printf("%s\n", ss);
    
    return 0;
}
/* //End of Code */

Please note that strrev() function used to reverse a string is not a standard C function. It is a function provided by certain compilers. If your compiler doesn't support strrev(), you'll need to write your own function to reverse a string.
