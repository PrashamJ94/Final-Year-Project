#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[101], b[101];
    scanf("%s %s", a, b);
    int x = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);
    memset(a, '0', x - strlen(a));
    memset(b, '0', x - strlen(b));
    
    char s[101] = "";
    int c = 0;
    for (int i = 0; i < x; i++) {
        int d = (b[i] - '0') + (a[x - i - 1] - '0') + c;
        if (d > 9) {
            s[i] = d % 10 + '0';
            c = 1;
        } else {
            s[i] = d + '0';
            c = 0;
        }
    }
    if (c == 1) {
        s[x] = '1';
        s[x + 1] = '\0';
    }
    int ans = atoi(s);
    printf("%d\n", ans);
    return 0;
}

// End of Code
