
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void solve(int n, int ls_xyh[][3], int* result) {
    int x0, y0, h0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (ls_xyh[i][2] > 0) {
            x0 = ls_xyh[i][0];
            y0 = ls_xyh[i][1];
            h0 = ls_xyh[i][2];
            found = true;
            break;
        }
    }
    if (!found) {
        return;
    }
    int cx, cy, ch;
    for (cx = 0; cx <= 100; cx++) {
        for (cy = 0; cy <= 100; cy++) {
            ch = h0 + abs(cx - x0) + abs(cy - y0);
            bool valid = true;
            for (int i = 0; i < n; i++) {
                int x = ls_xyh[i][0];
                int y = ls_xyh[i][1];
                int h = ls_xyh[i][2];
                if (h != (ch - abs(cx - x) - abs(cy - y) > 0 ? ch - abs(cx - x) - abs(cy - y) : 0)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result[0] = cx;
                result[1] = cy;
                result[2] = ch;
                return;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int ls_xyh[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &ls_xyh[i][0], &ls_xyh[i][1], &ls_xyh[i][2]);
    }
    int result[3] = {0, 0, 0};
    solve(n, ls_xyh, result);
    printf("%d %d %d\n", result[0], result[1], result[2]);
    return 0;
}

//End of Code
