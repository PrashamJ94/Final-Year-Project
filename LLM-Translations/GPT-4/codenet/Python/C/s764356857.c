#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int min = B * 10;
    int max = (B + 1) * 10 - 1;

    int ans = -1;
    for (int i = min; i <= max; i++) {
        if ((int)(i * 0.08) == A) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
} // 
