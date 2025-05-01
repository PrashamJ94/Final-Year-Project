#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int Black = 35;

int countBlack(int h, int w, int **m) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == Black) {
                count++;
            }
        }
    }
    return count;
}

int solve(int h, int w, int a, int **m) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            int **tmp = (int **)malloc(h * sizeof(int *));
            for (int j = 0; j < h; j++) {
                tmp[j] = (int *)malloc(w * sizeof(int));
                memcpy(tmp[j], m[j], w * sizeof(int));
            }
            for (int j = 0; j < h; j++) {
                int hPainted = (1 << j) & i;
                if (hPainted > 0) {
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                int wPainted = (1 << j) & k;
                if (wPainted > 0) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                result++;
            }

            for (int j = 0; j < h; j++) {
                free(tmp[j]);
            }
            free(tmp);
        }
    }
    return result;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);
    int **m = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        m[i] = (int *)malloc(w * sizeof(int));
        char s[w + 1];
        scanf("%s", s);
        for (int j = 0; j < w; j++) {
            m[i][j] = (int)s[j];
        }
    }

    int answer = solve(h, w, k, m);
    printf("%d\n", answer);

    for (int i = 0; i < h; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}
// 
