#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    int lst[3];
    lst[0] = A + B;
    lst[1] = A - B;
    lst[2] = A * B;

    int max = lst[0];
    for (int i = 1; i < 3; i++) {
        if (lst[i] > max) {
            max = lst[i];
        }
    }
    printf("%d\n", max);
    return 0;
} // 
