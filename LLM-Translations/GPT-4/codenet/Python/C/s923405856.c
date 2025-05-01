#include <stdio.h>

int main() {
    int n, a, res, s;

    while (1) {
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        res = -1111111111;
        s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            s = (s + a > a) ? s + a : a;
            res = (s > res) ? s : res;
        }

        printf("%d\n", res);
    }

    return 0;
}
// 
