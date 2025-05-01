#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, i, l, r, ans = 0;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++) {
        l = i;
        r = i + 1;
        while(r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }
        ans++;
        i = r;
    }
    printf("%d\n", ans);

    return 0;
}
// 
