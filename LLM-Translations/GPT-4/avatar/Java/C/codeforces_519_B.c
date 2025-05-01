
#include <stdio.h>

int main() {
    int n, a = 0, b = 0, c = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        a += temp;
    }

    for (int i = 0; i < n - 1; i++) {
        int temp;
        scanf("%d", &temp);
        b += temp;
    }

    for (int i = 0; i < n - 2; i++) {
        int temp;
        scanf("%d", &temp);
        c += temp;
    }

    int x = a - b, y = b - c;
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}
// //End of Code


