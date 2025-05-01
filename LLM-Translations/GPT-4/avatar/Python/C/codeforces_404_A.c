#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n][n+1];
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    bool flag = false;
    char d1 = s[0][0];
    char d2 = s[0][n-1];
    char rem = s[0][1];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (s[i][j] != d1) {
                    flag = true;
                    break;
                }
            } else if (i == n - j - 1) {
                if (s[i][j] != d2) {
                    flag = true;
                    break;
                }
            } else {
                if (s[i][j] != rem) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) break;
    }

    if (d1 == rem || d2 == rem || d1 != d2) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}

// End of Code.
