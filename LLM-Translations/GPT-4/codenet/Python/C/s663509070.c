#include <stdio.h>
#include <math.h>

int main() {
    int N, D;
    scanf("%d %d", &N, &D);
    int mat[N][D];
    for (int d = 0; d < N; d++) {
        for (int i = 0; i < D; i++) {
            scanf("%d", &mat[d][i]);
        }
    }

    int c = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist = 0;
            for (int k = 0; k < D; k++) {
                dist += (mat[i][k] - mat[j][k]) * (mat[i][k] - mat[j][k]);
            }
            dist = sqrt(dist);
            if ((int)dist == dist) {
                c++;
            }
        }
    }
    printf("%d\n", c);

    return 0;
}
// 
