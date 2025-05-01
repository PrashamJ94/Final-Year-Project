#include <stdio.h>
#include <limits.h>

int main() {
    int n, maxv, minv, ri;
    scanf("%d", &n);
    scanf("%d", &minv);
    maxv = INT_MIN;
    for (int i = 1; i < n; i++) {
        scanf("%d", &ri);
        if (maxv < ri - minv) {
            maxv = ri - minv;
        }
        if (minv > ri) {
            minv = ri;
        }
    }
    printf("%d\n", maxv);
    return 0;
}

// 
