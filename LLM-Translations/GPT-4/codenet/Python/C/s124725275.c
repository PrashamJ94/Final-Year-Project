#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 2147483648
#define MOD 1000000007
#define MAX 1000

int H, W, si, sj, ti, tj;
char S[MAX][MAX];
int D[MAX][MAX];

typedef struct {
    int cost;
    int x;
    int y;
} Node;

int cmp(const void *a, const void *b) {
    Node *na = (Node*)a;
    Node *nb = (Node*)b;
    return na->cost - nb->cost;
}

int main() {
    scanf("%d %d", &H, &W);
    scanf("%d %d", &si, &sj);
    scanf("%d %d", &ti, &tj);
    si--; sj--; ti--; tj--;

    for (int i = 0; i < H; i++) {
        scanf("%s", S[i]);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            D[i][j] = -1;
        }
    }

    Node que[MAX * MAX];
    int head = 0, tail = 0;
    que[tail++] = (Node){0, si, sj};

    int dx[] = {-2, -1, 0, 1, 2};
    int dy[] = {-2, -1, 0, 1, 2};

    while (head != tail) {
        Node cur = que[head++];
        if (D[cur.x][cur.y] != -1) continue;
        D[cur.x][cur.y] = cur.cost;

        for (int di = 0; di < 5; di++) {
            for (int dj = 0; dj < 5; dj++) {
                int ni = cur.x + dx[di];
                int nj = cur.y + dy[dj];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W || D[ni][nj] != -1 || S[ni][nj] == '#') continue;
                if ((di == 2 && (dj == 1 || dj == 3)) || (dj == 2 && (di == 1 || di == 3))) {
                    que[--head] = (Node){cur.cost, ni, nj};
                } else {
                    que[tail++] = (Node){cur.cost + 1, ni, nj};
                }
            }
        }

        if (tail - head >= 2) {
            qsort(que + head, tail - head, sizeof(Node), cmp);
        }
    }

    printf("%d\n", D[ti][tj]);
    return 0;
}

