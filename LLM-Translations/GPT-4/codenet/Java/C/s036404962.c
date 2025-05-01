#include <stdio.h>

int main() {

    int X, t;
    scanf("%d%d", &X, &t);

    if(X >= t) {
        printf("%d\n", X - t);
    } else if (X < t) {
        printf("0\n");
    }

    return 0;
}
// 
