
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void duplicatePatterns(int elems[], int k, int pattern[], int depth, int result[][4], int *index) {
    if (depth == k) {
        memcpy(result[*index], pattern, k * sizeof(int));
        ++(*index);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        pattern[depth] = elems[i];
        duplicatePatterns(elems, k, pattern, depth + 1, result, index);
    }
}

int main() {
    int a, b, c, k;
    scanf("%d %d %d %d", &a, &b, &c, &k);

    int elems[] = {0, 1, 2, 3};
    int result[256][4];
    int pattern[4];
    int index = 0;
    duplicatePatterns(elems, k, pattern, 0, result, &index);

    for (int i = 0; i < index; ++i) {
        int r = a, g = b, b = c;
        for (int j = 0; j < k; ++j) {
            if (result[i][j] == 0) {
                continue;
            } else if (result[i][j] == 1) {
                r *= 2;
            } else if (result[i][j] == 2) {
                g *= 2;
            } else if (result[i][j] == 3) {
                b *= 2;
            }
        }

        if (g > r && b > g) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}


