#include <stdio.h>
#include <limits.h>

int main() {
    int A, B, C, X, Y;
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    int ans = INT_MAX;

    for (int k = 0; k <= (X > Y ? X : Y); k++) {
        int total = 2 * C * k + A * (X - k > 0 ? X - k : 0) + B * (Y - k > 0 ? Y - k : 0);
        if (total < ans) {
            ans = total;
        }
    }

    printf("%d\n", ans);
    return 0;
}

// 
