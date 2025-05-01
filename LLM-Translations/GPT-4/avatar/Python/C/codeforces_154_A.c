#include <stdio.h>
#include <string.h>

int main() {
    char s[1000], x[2];
    int n, ans = 0, a = 0, b = 0;
    scanf("%s", s);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", x);
        a = 0, b = 0;
        for(int j = 0; j < strlen(s); j++) {
            if(s[j] == x[0]) {
                a += 1;
            } else if(s[j] == x[1]) {
                b += 1;
            } else {
                ans = ans + ((a < b) ? a : b);
                a = 0, b = 0;
            }
        }
        ans = ans + ((a < b) ? a : b);
    }
    printf("%d", ans);
    return 0;
} // End of Code
