#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int m[10][3][10] = {0};
    int b, f, r, v;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &b, &f, &r, &v);
        m[b-1][f-1][r-1] += v;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++) {
                printf(" %d", m[i][j][k]);
            }
            printf("\n");
        }
        if (i < 3) {
            printf("####################\n");
        }
    }
    return 0;
} // 
