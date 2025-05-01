#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

int shortest_path(int C[SIZE][SIZE], int src, int dest) {
    int dist[SIZE], visited[SIZE], min, min_idx;
    for (int i = 0; i < SIZE; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < SIZE - 1; count++) {
        min = INT_MAX;
        for (int i = 0; i < SIZE; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                min_idx = i;
            }
        }
        visited[min_idx] = 1;
        for (int i = 0; i < SIZE; i++) {
            if (!visited[i] && C[min_idx][i] && dist[min_idx] != INT_MAX &&
                dist[min_idx] + C[min_idx][i] < dist[i]) {
                dist[i] = dist[min_idx] + C[min_idx][i];
            }
        }
    }
    return dist[dest];
}

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    int C[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &C[i][j]);
        }
    }
    int A[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int d[SIZE];
    for (int i = 0; i < SIZE; i++) {
        if (i == 1) {
            continue;
        }
        d[i] = shortest_path(C, i, 1);
    }

    int s = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int a = A[i][j];
            if (a == -1 || a == 1) {
                continue;
            }
            s += d[a];
        }
    }
    printf("%d\n", s);
    return 0;
}
// 
