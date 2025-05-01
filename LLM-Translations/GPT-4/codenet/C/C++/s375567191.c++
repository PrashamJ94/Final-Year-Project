#include <iostream>
#include <vector>
using namespace std;

#define MAX 101
#define WHITE 0
#define BLACK 2
#define GRAY 1

int time, n;
vector<vector<int>> g(MAX, vector<int>(MAX, 0));
vector<int> d(MAX), f(MAX), color(MAX, WHITE);

void visit(int u) {
    int i;

    color[u] = GRAY;
    d[u] = ++time;

    for (i = 0; i < n; i++) {
        if (g[u][i] == 0)
            continue;
        if (color[i] == WHITE)
            visit(i);
    }

    color[u] = BLACK;
    f[u] = ++time;
}

void dfs() {
    int i;
    time = 0;

    for (i = 0; i < n; i++)
        if (color[i] == WHITE)
            visit(i);

    for (i = 0; i < n; i++)
        printf("%d %d %d\n", i + 1, d[i], f[i]);
}

int main() {
    int i, j, x, y, z;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> x >> y;
        for (j = 0; j < y; j++) {
            cin >> z;
            g[x - 1][z - 1] = 1;
        }
    }

    dfs();
    return 0;
}
// 
