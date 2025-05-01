#include <stdio.h>
#include <math.h>

int main() {
    int a, v, b, w, t;
    scanf("%d %d", &a, &v);
    scanf("%d %d", &b, &w);
    scanf("%d", &t);

    if (a == b) {
        printf("YES\n");
    } else if (v <= w) {
        printf("NO\n");
    } else {
        if (t < abs(a - b) / (v - w)) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}
// 
