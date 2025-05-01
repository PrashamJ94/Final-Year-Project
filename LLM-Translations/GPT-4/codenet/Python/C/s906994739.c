#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int F[n][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    int P[n][11];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++) {
            scanf("%d", &P[i][j]);
        }
    }

    int ans = INT_MIN;

    for (int i = 1; i < (1 << 10); i++) {
        int tmp = 0;
        int lst[n];
        for (int k = 0; k < n; k++) {
            lst[k] = 0;
        }

        for (int j = 0; j < 10; j++) { // time zone
            if ((i >> j) & 1) { // if open
                for (int k = 0; k < n; k++) {
                    lst[k] += F[k][j];
                }
            }
        }

        for (int k = 0; k < n; k++) {
            tmp += P[k][lst[k]];
        }

        ans = (ans > tmp) ? ans : tmp;
    }

    printf("%d\n", ans);

    return 0;
}
// 
