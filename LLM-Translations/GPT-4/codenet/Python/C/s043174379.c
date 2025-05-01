#include <stdio.h>

int main() {
    int H, W, h, w, ans;
    scanf("%d %d", &H, &W);
    scanf("%d %d", &h, &w);
    ans = H * W - (h * W + w * H - h * w);
    printf("%d\n", ans);
    return 0;
}


