#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100001

int n;
int color[MAX_VERTICES];
int V[MAX_VERTICES][MAX_VERTICES][2];
int V_count[MAX_VERTICES];

void add_edge(int u, int v, int w) {
    V[u][V_count[u]][0] = v;
    V[u][V_count[u]][1] = w;
    V_count[u]++;
    V[v][V_count[v]][0] = u;
    V[v][V_count[v]][1] = w;
    V_count[v]++;
}

bool dfs(int i) {
    for (int j = 0; j < V_count[i]; j++) {
        int v = V[i][j][0];
        int w = V[i][j][1];

        if (w % 2 == 0) {
            if (color[v] == -1) {
                color[v] = color[i];
            } else if (color[v] == color[i]) {
                continue;
            } else if (color[v] != color[i]) {
                return false;
            }
        } else {
            if (color[v] == -1) {
                color[v] = color[i] ? 0 : 1;
            } else if (color[v] == color[i]) {
                return false;
            } else if (color[v] != color[i]) {
                continue;
            }
        }
        if (!dfs(v)) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    for (int i = 1; i <= n; i++) {
        color[i] = -1;
    }

    while (true) {
        int i = 0;
        for (int j = 1; j <= n; j++) {
            if (color[j] == -1) {
                i = j;
                color[i] = 0;
                break;
            }
        }

        if (i == 0) {
            for (int j = 1; j <= n; j++) {
                printf("%d\n", color[j]);
            }
            break;
        } else {
            if (!dfs(i)) {
                printf("No\n");
                break;
            }
        }
    }

    return 0;
}
// 
