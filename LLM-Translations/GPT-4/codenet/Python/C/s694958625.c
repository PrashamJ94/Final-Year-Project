#include <stdio.h>

int main() {
    int x, a, b;
    scanf("%d", &x);
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d\n", (x-a) % b);
    return 0;
}
// 
