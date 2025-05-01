//c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, Q;
    scanf("%d%d%d", &N, &M, &Q);

    int Q_groups[Q][4];
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &Q_groups[i][j]);
        }
    }

    int max_score = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j++) {
            int temp_score = 0;
            for (int k = 0; k < Q; k++) {
                if (j - i == Q_groups[k][2]) {
                    temp_score += Q_groups[k][3];
                }
            }
            if (temp_score > max_score) {
                max_score = temp_score;
            }
        }
    }

    printf("%d\n", max_score);

    return 0;
}

//
