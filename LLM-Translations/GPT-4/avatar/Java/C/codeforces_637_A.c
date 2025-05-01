
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, v, max = 0;
    scanf("%d", &n);
    int ara[n];
    int map[1001] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        ara[i] = v;
        map[v]++;
    }

    for (int i = 0; i < 1001; i++) {
        if (map[i] > max) {
            max = map[i];
        }
    }

    int mm[1001] = {0};
    for (int i = 0; i < n; i++) {
        mm[ara[i]]++;
        if (mm[ara[i]] == max) {
            printf("%d\n", ara[i]);
            break;
        }
    }

    return 0;
}

// //End of Code.
