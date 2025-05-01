
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    
    char G[H+2][W+2];
    for (int i = 0; i < H+2; i++) {
        if (i == 0 || i == H+1) {
            for (int j = 0; j < W+2; j++) {
                G[i][j] = '#';
            }
        } else {
            scanf(" %[^\\n]", &G[i][1]);
            G[i][0] = G[i][W+1] = '#';
        }
    }
    
    int ans = 0;
    for (int sx = 0; sx < W+2; sx++) {
        for (int sy = 0; sy < H+2; sy++) {
            if (G[sy][sx] == '.') {
                int dist[H+2][W+2];
                bool visited[H+2][W+2];
                memset(dist, -1, sizeof(dist));
                memset(visited, false, sizeof(visited));
                
                int queue_size = (H+2) * (W+2);
                int queue[queue_size][2];
                int front = 0, back = 0;
                
                queue[back][0] = sx;
                queue[back++][1] = sy;
                dist[sy][sx] = 0;
                visited[sy][sx] = true;
                
                while (front != back) {
                    int x = queue[front][0];
                    int y = queue[front++][1];
                    
                    if (G[y][x+1] == '.' && !visited[y][x+1]) {
                        queue[back][0] = x+1;
                        queue[back++][1] = y;
                        dist[y][x+1] = dist[y][x] + 1;
                        visited[y][x+1] = true;
                    }
                    
                    if (G[y][x-1] == '.' && !visited[y][x-1]) {
                        queue[back][0] = x-1;
                        queue[back++][1] = y;
                        dist[y][x-1] = dist[y][x] + 1;
                        visited[y][x-1] = true;
                    }
                    
                    if (G[y+1][x] == '.' && !visited[y+1][x]) {
                        queue[back][0] = x;
                        queue[back++][1] = y+1;
                        dist[y+1][x] = dist[y][x] + 1;
                        visited[y+1][x] = true;
                    }
                    
                    if (G[y-1][x] == '.' && !visited[y-1][x]) {
                        queue[back][0] = x;
                        queue[back++][1] = y-1;
                        dist[y-1][x] = dist[y][x] + 1;
                        visited[y-1][x] = true;
                    }
                }
                
                for (int i = 0; i < W+2; i++) {
                    for (int j = 0; j < H+2; j++) {
                        ans = ans > dist[j][i] ? ans : dist[j][i];
                    }
                }
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}


