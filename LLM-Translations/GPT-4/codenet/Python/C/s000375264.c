#include <stdio.h>

int main() {
    int X, t, answer;
    scanf("%d %d", &X, &t);

    if (X > t) {
        answer = X - t;
    } else if (X <= t) {
        answer = 0;
    }

    printf("%d\n", answer);
    return 0;
}
// 
