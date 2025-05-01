#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct {
    int edges[MAX_NODES];
    int num_edges;
} Node;

typedef struct {
    int a, b;
} Edge;

void bfs(int v, int N, Node G[], int *K, int E[][2]) {
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int node2color[MAX_NODES];
    for (int i = 0; i < N; i++) {
        node2color[i] = -1;
    }
    queue[rear++] = v;
    visited[v] = true;
    while (front != rear) {
        int q = queue[front++];
        int color = 0;
        for (int i = 0; i < G[q].num_edges; i++) {
            int nex = G[q].edges[i];
            if (visited[nex]) {
                continue;
            }
            visited[nex] = true;
            color += 1;
            if (color == node2color[q]) {
                color += 1;
            }
            node2color[nex] = color;
            E[nex][0] = q;
            E[nex][1] = color;
            queue[rear++] = nex;
        }
        *K = (*K < color) ? color : *K;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Node G[MAX_NODES];
    for (int i = 0; i < N; i++) {
        G[i].num_edges = 0;
    }
    int E[MAX_NODES][2];
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].edges[G[a].num_edges++] = b;
        G[b].edges[G[b].num_edges++] = a;
    }
    int K = -1;
    bfs(0, N, G, &K, E);
    printf("%d\n", K);
    for (int i = 1; i < N; i++) {
        printf("%d\n", E[i][1]);
    }
    return 0;
}

// End of Code
