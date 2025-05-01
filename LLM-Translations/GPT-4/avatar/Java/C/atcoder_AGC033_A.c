
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    char A[H][W];
    int queue[H * W][3], queue_start = 0, queue_end = 0;
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                int start[] = {i, j, 0};
                memcpy(queue[queue_end++], start, sizeof(start));
            }
        }
    }
    int flag[H][W];
    memset(flag, 0, sizeof(flag));
    int ans = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while (queue_start != queue_end) {
        int y = queue[queue_start][0];
        int x = queue[queue_start][1];
        int depth = queue[queue_start][2];
        queue_start++;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (0 <= ny && ny <= H - 1 && 0 <= nx && nx <= W - 1) {
                if (flag[ny][nx] == 0 && A[ny][nx] == '.') {
                    flag[ny][nx] = 1;
                    int queue_add[] = {ny, nx, depth + 1};
                    memcpy(queue[queue_end++], queue_add, sizeof(queue_add));
                    ans = depth + 1;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

// //End of Code
