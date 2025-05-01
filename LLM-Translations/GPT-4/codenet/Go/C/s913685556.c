
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    int A, B, mx;
    scanf("%d %d", &A, &B);

    mx = max(A + B, A - B);
    mx = max(mx, A * B);
    printf("%d\n", mx);

    return 0;
}

// 
