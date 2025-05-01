#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<vector<int>> g;
int ci = 0, cb = 0, cc = 0;

bool dfs(int x) {
    stack<pair<int, int>> stk;
    bool flag = true;
    stk.push({x, 1});
    while (!stk.empty()) {
        int u = stk.top().first;
        int col = stk.top().second;
        stk.pop();
        if (vis[u]) {
            flag &= (vis[u] == col);
            continue;
        }
        vis[u] = col;
        for (int i : g[u]) {
            stk.push({i, 3 - col});
        }
    }
    return flag;
}

int main() {
    int n, m;
    cin >> n >> m;
    vis.resize(n + 1);
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (g[i].empty()) {
                ci++;
            } else {
                if (dfs(i)) {
                    cb++;
                } else {
                    cc++;
                }
            }
        }
    }
    cout << ci * ci + 2 * ci * (n - ci) + cc * cc + 2 * cb * cc + 2 * cb * cb << endl;
    return 0;
}

// End of Code.
