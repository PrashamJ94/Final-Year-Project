
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int find_group(int n) {
    int group1[] = {1, 3, 5, 7, 8, 10, 12};
    int group2[] = {4, 6, 9, 11};

    for (int i = 0; i < sizeof(group1) / sizeof(int); i++) {
        if (n == group1[i]) {
            return 1;
        }
    }

    for (int i = 0; i < sizeof(group2) / sizeof(int); i++) {
        if (n == group2[i]) {
            return 2;
        }
    }

    return 3;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    int xt = find_group(x);
    int yt = find_group(y);

    if (xt == yt) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}


