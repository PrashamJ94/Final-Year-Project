#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> colors;
map<int, map<int, int>> friends;

void dfs(int p, int length) {
    if (colors[p] != -1) return;
    colors[p] = length % 2;
    for (auto it = friends[p].begin(); it != friends[p].end(); it++) {
        dfs(it->first, length + it->second);
    }
}

int main() {
    int n;
    cin >> n;
    colors.resize(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        friends[u][v] = w;
        friends[v][u] = w;
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        cout << colors[i] << endl;
    }
    return 0;
}
// //End of Code
