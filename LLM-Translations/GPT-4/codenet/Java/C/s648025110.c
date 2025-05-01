#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int h[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    int ans = 0;
    int out = 0;

    for(i = 0; i < n; i++) {
        if(out < h[i]) {
            ans += h[i] - out;
            out =  h[i];
        } else {
            out = h[i];
        }
    }

    printf("%d\n", ans);
    return 0;
}
// 
