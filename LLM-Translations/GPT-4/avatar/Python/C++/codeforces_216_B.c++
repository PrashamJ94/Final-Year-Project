#include<bits/stdc++.h>
using namespace std;

pair<int, int> dfs(map<int, set<int>>& g, set<int>& seen, int i) {
    if (seen.find(i) != seen.end()) {
        return make_pair(0, 0);
    }
    seen.insert(i);
    int nodes = 1;
    int edges = g[i].size();
    for(auto j : g[i]) {
        pair<int, int> result = dfs(g, seen, j);
        nodes += result.first;
        edges += result.second;
    }
    return make_pair(nodes, edges);
}

int solve () {
    int n, m;
    if(!(cin >> n >> m)) return 0;
    map<int, set<int>> g;
    set<int> seen;
    for (int i = 1; i <= n; i++) {
        g[i] = set<int>();
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            pair<int, int> result = dfs(g, seen, i);
            if (result.first > 1 && result.first % 2 == 1 && 2 * result.first == result.second) {
                ans++;
            }
        }
    }
    if ((n - ans) % 2 == 1) {
        ans++;
    }
    cout << ans << "\n";
    return 1;
}

int main() {
    while (solve()) {}
    return 0;
}

// End of Code.
