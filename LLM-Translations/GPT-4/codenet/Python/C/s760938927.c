#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int h, w, ka;
    scanf("%d %d %d", &h, &w, &ka);

    char mat[h][w];
    for (int i = 0; i < h; i++) {
        scanf("%s", mat[i]);
    }

    int ans = 0;
    for (int i = 0; i < (1 << (h + w)); i++) {
        char b[h + w + 1];
        sprintf(b, "%0*d", h + w, atoi(_itoa(i, b, 2)));
        char *rs = b;
        char *cs = b + h;
        int ct = 0;

        for (int l = 0; l < h; l++) {
            for (int k = 0; k < w; k++) {
                if (mat[l][k] == '#' && rs[l] == '0' && cs[k] == '0') {
                    ct++;
                }
            }
        }

        if (ct == ka) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
// 
