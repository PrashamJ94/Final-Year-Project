#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000000 + 7
#define ALPHABET_NUM 26
#define INF_INT64 9223372036854775807
#define INF_BIT60 1152921504606846976
#define INF_INT32 2147483647
#define INF_BIT30 1073741824
#define NIL -1

#define WHITE 0
#define GRAY 1
#define BLACK 2

bool dpx[8000][20000], dpy[8000][20000];

int main() {
    char S[10001];
    int x, y;
    scanf("%s", S);
    scanf("%d%d", &x, &y);

    int F[10000] = {0}, cur = 0, idx = 0;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F[idx++] = cur;
            cur = 0;
        }
    }
    F[idx++] = cur;

    int evens[10000] = {0}, odds[10000] = {0}, evenIdx = 0, oddIdx = 0;
    for (int i = 0; i < idx; i++) {
        if (i % 2 == 0) {
            evens[evenIdx++] = F[i];
        } else {
            odds[oddIdx++] = F[i];
        }
    }

    dpx[0][10000] = dpy[0][10000] = true;
    for (int i = 0; i < evenIdx; i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i != 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }
    for (int i = 0; i < oddIdx; i++) {
        int val = odds[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
            }
            if (j - val >= 2000) {
                dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
            }
        }
    }

    if (dpx[evenIdx][x + 10000] && dpy[oddIdx][y + 10000]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// 
