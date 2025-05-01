#include <stdio.h>
#include <stdbool.h>

int main() {
    char str[4][5];
    for (int i = 0; i < 4; i++) {
        scanf("%s", str[i]);
    }

    bool yes = false;
    for (int u = 0; u < 3; u++) {
        for (int i = 0; i < 3; i++) {
            if ((str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i])) ||
                (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))) {
                yes = true;
                printf("YES\n");
                break;
            }
        }
        if (yes) {
            break;
        }
    }

    if (!yes) {
        printf("NO\n");
    }

    return 0;
}
// //End of Code
