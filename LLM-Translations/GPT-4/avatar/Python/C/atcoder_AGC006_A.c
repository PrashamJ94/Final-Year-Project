
#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, cnt = 0;
    scanf("%d", &n);

    char s[n+1], t[n+1];
    scanf("%s", s);
    scanf("%s", t);

    if (strcmp(s, t) == 0) {
        printf("%d", n);
    } else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n - i; j++) {
                if (s[i + j] != t[j]) {
                    break;
                }
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }
        printf("%d", 2 * n - cnt);
    }

    return 0;
} // End of Code


