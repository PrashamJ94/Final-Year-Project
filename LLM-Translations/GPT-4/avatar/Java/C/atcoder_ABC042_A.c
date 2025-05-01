#include <stdio.h>

int main() {
    int x, a, y;
    char h[3] = "NO";

    scanf("%d %d %d", &x, &a, &y);

    if ((x == 5 || x == 7) || (a == 5 || a == 7) || (y == 5 || y == 7)) {
        if (x + y + a == 17) {
            snprintf(h, sizeof(h), "YES");
        }
    }

    printf("%s\n", h);
    return 0;
}

// //End of Code.
