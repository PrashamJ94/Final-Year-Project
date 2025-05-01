
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char arrs[n][m + 1];
    for (int i = 0; i < n; i++) {
        scanf("%s", arrs[i]);
    }
    int length[n];
    int index = 0;
    int returnDex = 0;
    for (int i = 0; i < n; i++) {
        char *tmp = arrs[i];
        char *dexG = strchr(tmp, 'G');
        char *dexS = strchr(tmp, 'S');
        if (dexG > dexS) {
            returnDex = -1;
        }
        length[index++] = dexS - dexG;
    }
    int set[1001] = {0};
    for (int i = 0; i < n; i++) {
        set[length[i]] = 1;
    }
    int setSize = 0;
    for (int i = 0; i < 1001; i++) {
        if (set[i]) {
            setSize++;
        }
    }
    if (returnDex == -1) {
        printf("%d\n", returnDex);
    } else {
        printf("%d\n", setSize);
    }
    return 0;
}

// //End of Code
