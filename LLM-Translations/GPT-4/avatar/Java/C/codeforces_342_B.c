#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int a;
    int b;
} Pair;

int main() {
    int m, s, f;
    scanf("%*d %d %d %d", &m, &s, &f);

    int maxT = -1;
    Pair map[1001] = {0};
    bool hasKey[1001] = {false};

    for (int i = 0; i < m; i++) {
        int k, a, b;
        scanf("%d %d %d", &k, &a, &b);
        map[k].a = a;
        map[k].b = b;
        hasKey[k] = true;
        maxT = (maxT < k) ? k : maxT;
    }

    char actions[1001] = {0};
    int actionIndex = 0;
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? +1 : -1;
    int cur = s;
    int a = -1;
    int b = -1;

    for (int t = 1; t <= maxT; t++) {
        if (hasKey[t]) {
            a = map[t].a;
            b = map[t].b;
        }
        if (hasKey[t] && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions[actionIndex++] = 'X';
        } else {
            actions[actionIndex++] = M;
            cur += d;
        }
        if (cur == f) {
            break;
        }
    }

    while (cur != f) {
        actions[actionIndex++] = M;
        cur += d;
    }

    printf("%s\n", actions);

    return 0;
}
// //End of Code
