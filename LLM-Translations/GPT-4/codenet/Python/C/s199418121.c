#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, B;
    float tempB;
    scanf("%d %f", &A, &tempB);

    B = (int)(tempB * 100);
    printf("%d\n", (A * B) / 100);

    return 0;
}
// 
