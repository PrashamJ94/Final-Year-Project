#include <stdio.h>

int main() {
    int n, c = 0, flg = 0;
    scanf("%d", &n);

    while (n-- > 0) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (x == y) {
            c++;
            if (c >= 3) {
                flg = 1;
            }
        } else {
            c = 0;
        }
    }

    if (flg == 0) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}
// 
