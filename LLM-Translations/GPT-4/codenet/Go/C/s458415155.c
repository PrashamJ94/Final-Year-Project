#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int iabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int solve(int n, int heights[]) {
    int t[n + 1];
    for (int i = 0; i <= n; i++) {
        t[i] = INT_MAX;
    }

    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (int v = t[i - 1] + iabs(heights[i] - heights[i - 1]); v < t[i]) {
            t[i] = v;
        }
        if (1 < i) {
            if (int v = t[i - 2] + iabs(heights[i] - heights[i - 2]); v < t[i]) {
                t[i] = v;
            }
        }
    }

    return t[n - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int ans = solve(n, heights);
    printf("%d\n", ans);
    return 0;
}

// 
