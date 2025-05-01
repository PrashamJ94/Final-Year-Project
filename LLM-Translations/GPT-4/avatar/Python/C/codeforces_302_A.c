#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char s[n];
    scanf("%s", s);
    int sa = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '-')
            sa++;
    }
    sa = (n - sa < sa) ? n - sa : sa;
    int a, b;
    char ss[m];
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        b -= a;
        if(b % 2 && b <= sa << 1)
            ss[i] = '1';
        else
            ss[i] = '0';
    }
    for(int i = 0; i < m; i++)
        printf("%c\n", ss[i]);
    return 0;
} // End of Code

//Please note that the C language does not have a direct equivalent for Python's "count" method used with strings. Here, I've implemented it with a for loop that iterates over the string and increments a counter when it encounters a "-".
