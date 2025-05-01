#include <stdio.h>

int main() {
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);

    int games_count = 0;
    for (int i = a; i <= x; ++i) {
        if (i <= b) continue;
        for (int j = b; j <= y; ++j) {
            if (i > j) {
                ++games_count;
            }
        }
    }

    printf("%d\n", games_count);
    for (int i = a; i <= x; ++i) {
        if (i <= b) continue;
        for (int j = b; j <= y; ++j) {
            if (i > j) {
                printf("%d %d\n", i, j);
            }
        }
    }

    return 0;
}

// End of Code
