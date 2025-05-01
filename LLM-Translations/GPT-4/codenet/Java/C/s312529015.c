#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    if (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) {
        printf("Possible\n");
    } else {
        printf("Impossible\n");
    }
    return 0;
}
// 
