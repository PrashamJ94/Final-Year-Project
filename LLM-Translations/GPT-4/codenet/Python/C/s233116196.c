#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int G[N+1][N+1];
    memset(G, 0, sizeof(G));

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }

    int col[N+1];
    for (int i = 0; i <= N; i++) {
        col[i] = -1;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (col[i] < 0) {
            col[i] = cnt;
            int que[N+1], head = 0, tail = 0;
            que[tail++] = i;

            while (head < tail) {
                int x = que[head++];
                for (int y = 1; y <= N; y++) {
                    if (G[x][y] && col[y] < 0) {
                        col[y] = cnt;
                        que[tail++] = y;
                    }
                }
            }

            cnt += 1;
        }
    }

    int cmax = col[0];
    for (int i = 1; i <= N; i++) {
        if (col[i] > cmax) {
            cmax = col[i];
        }
    }

    printf("%d\n", cmax);

    return 0;
}
