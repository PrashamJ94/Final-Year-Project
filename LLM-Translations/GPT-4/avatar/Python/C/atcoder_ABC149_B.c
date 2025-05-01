#include <stdio.h>

int main() {
    int cookies[3], leftOver, takahashi;
    scanf("%d %d %d", &cookies[0], &cookies[1], &cookies[2]);
    leftOver = cookies[0] - cookies[2];
    takahashi = leftOver > 0 ? leftOver : 0;
    printf("%d %d\n", takahashi, takahashi > 0 ? cookies[1] : (cookies[1] - abs(leftOver) > 0 ? cookies[1] - abs(leftOver) : 0));
    return 0;
}

// End of Code
