#include<bits/stdc++.h>
using namespace std;

class Main {
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> color;
    long one;
    long bipartite;
    long count;
    bool mujun;

    int dfs(int a, int c) {
        if (visited[a]) {
            if (color[a] >= 0 && color[a] != c)
                mujun = true;
            return 0;
        }
        visited[a] = true;
        color[a] = c;
        int total = 1;
        for (int b : graph[a]) {
            total += dfs(b, 1 - c);
        }
        return total;
    }

public:
    void run() {
        int n, m;
        cin >> n >> m;
        graph.resize(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        visited.resize(n, false);
        color.resize(n, -1);
        one = 0;
        bipartite = 0;
        count = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            count++;
            mujun = false;
            int kind = dfs(i, 0);
            if (kind == 1) one++;
            else if (!mujun) bipartite++;
        }
        long total = one * (2 * n - one);
        total += (count - one) * (count - one);
        total += bipartite * bipartite;
        cout << total << endl;
    }
};

int main() {
    Main().run();
    return 0;
}

// //End of Code
