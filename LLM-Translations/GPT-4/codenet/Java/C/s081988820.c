#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    int H, W;
    scanf("%d %d", &H, &W);
    int c[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    int min[10];
    for (int i = 0; i < 10; i++) {
        min[i] = c[i][1];
    }
    for (int tc = 0; tc < 10; tc++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                min[i] = fmin(min[i], c[i][j] + min[j]);
            }
        }
    }
    int ans = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            int A;
            scanf("%d", &A);
            if (A >= 0) {
                ans += min[A];
            }
        }
    }
    printf("%d\n", ans);
}

// 
