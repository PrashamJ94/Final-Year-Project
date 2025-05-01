#include <stdio.h>

int main() {
    int h, a;
    scanf("%d %d", &h, &a);

    int ans = h / a;
    int ama = h % a;

    if (ama != 0) {
        ans += 1;
    }
    printf("%d\n", ans);

    return 0;
}
// 
