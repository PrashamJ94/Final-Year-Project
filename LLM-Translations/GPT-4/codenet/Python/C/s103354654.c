#include <stdio.h>

int main() {
    int W, H, x, y, r;
    scanf("%d %d %d %d %d", &W, &H, &x, &y, &r);

    if (x >= r && (W - r) >= x) {
        if (y >= r && (H - r) >= y) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else {
        printf("No\n");
    }

    return 0;
} // 
