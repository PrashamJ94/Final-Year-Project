#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int max_level;
    scanf("%d", &max_level);

    int x_count, y_count;
    scanf("%d", &x_count);
    int x[x_count];
    for (int i = 0; i < x_count; i++) {
        scanf("%d", &x[i]);
    }

    scanf("%d", &y_count);
    int y[y_count];
    for (int i = 0; i < y_count; i++) {
        scanf("%d", &y[i]);
    }

    bool levels[max_level + 1];
    for (int i = 1; i <= max_level; i++) {
        levels[i] = false;
    }

    for (int i = 0; i < x_count; i++) {
        if (x[i] != 0) {
            levels[x[i]] = true;
        }
    }

    for (int i = 0; i < y_count; i++) {
        if (y[i] != 0) {
            levels[y[i]] = true;
        }
    }

    bool can_pass = true;
    for (int i = 1; i <= max_level; i++) {
        if (!levels[i]) {
            can_pass = false;
            break;
        }
    }

    if (can_pass) {
        printf("I become the guy.\n");
    } else {
        printf("Oh, my keyboard!\n");
    }

    return 0;
}
// End of Code
