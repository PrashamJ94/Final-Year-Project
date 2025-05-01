#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int x = 0, y = 0;
    int t = 0;
    int n;
    scanf("%d", &n);
    char str[n + 1];
    scanf("%s", str);
    int len = strlen(str);
    char l[len];
    strcpy(l, str);

    for (int i = 0; i < len; i++) {
        if (l[i] != '4' && l[i] != '7') {
            t = 1;
        }
    }

    if (t == 1) {
        printf("NO\n");
    } else {
        for (int i = 0; i < len / 2; i++) {
            x = x + (l[i] - '0');
        }

        for (int i = len - 1; i > (len / 2) - 1; i--) {
            y = y + (l[i] - '0');
        }

        if (x == y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

// //End of Code
