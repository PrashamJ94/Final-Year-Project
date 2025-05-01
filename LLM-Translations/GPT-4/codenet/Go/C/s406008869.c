
#include <stdio.h>
#include <stdbool.h>

int e[10][10];
int n, m;

void printEdge() {
    for (int i = 1; i < n + 1; i++) {
        printf("%d: ", i);
        for (int j = 0; j < 10; j++) {
            if(e[i][j] != 0) {
                printf("%d ", e[i][j]);
            }
        }
        printf("\n");
    }
}

int dfs(int v, bool visited[]) {
    bool comp = true;
    for (int i = 1; i < n + 1; i++) {
        if (!visited[i]) {
            comp = false;
        }
    }

    if (comp) {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < 10; i++) {
        int ne = e[v][i];
        if (ne == 0) {
            continue;
        }
        if (visited[ne]) {
            continue;
        }
        visited[ne] = true;
        int rst = dfs(ne, visited);
        count += rst;
        visited[ne] = false;
    }
    return count;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    bool visited[10] = {false};
    visited[1] = true;
    int count = dfs(1, visited);
    printf("%d\n", count);

    return 0;
}

// 
