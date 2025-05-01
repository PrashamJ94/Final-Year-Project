
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int h[n];
    bool good[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        good[i] = true;
    }
    for (int i = 0; i < m; i++) {
        int ai, bi;
        scanf("%d %d", &ai, &bi);
        ai--;
        bi--;
        if (h[ai] > h[bi]) {
            good[bi] = false;
        } else if (h[ai] < h[bi]) {
            good[ai] = false;
        } else {
            good[ai] = false;
            good[bi] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}

// 
