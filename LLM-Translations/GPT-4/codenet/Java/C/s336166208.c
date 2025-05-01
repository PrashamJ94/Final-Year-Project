#include <stdio.h>

int main() {
    int info[4][3][10] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++) {
                info[i][j][k] = 0;
            }
        }
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int built, floor, room, num;
        scanf("%d %d %d %d", &built, &floor, &room, &num);
        info[built - 1][floor - 1][room - 1] += num;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++) {
                printf(" %d", info[i][j][k]);
            }
            printf("\n");
        }
        if (i != 4 - 1) {
            printf("####################\n");
        }
    }

    return 0;
}
// 
