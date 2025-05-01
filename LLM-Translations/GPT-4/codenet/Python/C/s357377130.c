#include <stdio.h>

int main() {
    int A, B, K;
    scanf("%d %d %d", &A, &B, &K);

    if (A + K - 1 >= B - K + 1) {
        while (A <= B) {
            printf("%d\n", A);
            A++;
        }
    } else {
        int i = 0;
        while (i <= K - 1) {
            printf("%d\n", A + i);
            i++;
        }
        while (B - K + 1 <= B) {
            printf("%d\n", B - K + 1);
            K--;
        }
    }

    return 0;
}
// 
