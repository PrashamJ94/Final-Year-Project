#include <stdio.h>

int main() {
    int n, i, count = 1, now = 0, bef = 0;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 1; i < n; i++) {
        if(a[i-1] < a[i]) {
            now = 1;
        } else if(a[i-1] > a[i]) {
            now = -1;
        } else {
            continue;
        }
        if(bef == 0) {
            bef = now;
        }
        if(bef != now) {
            count++;
            bef = 0;
        }
    }
    printf("%d\n", count);
    return 0;
}
// 
