#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int i, unordered_map<int, vector<pair<int, int>>> &V, vector<int> &color) {
    for (pair<int, int> vw : V[i]) {
        int v = vw.first;
        int w = vw.second;
        
        if (w % 2 == 0) {
            if (color[v] == -1) {
                color[v] = color[i];
            } else if (color[v] == color[i]) {
                continue;
            }
        } else {
            if (color[v] == -1) {
                color[v] = 1 - color[i];
            } else if (color[v] == color[i]) {
                return;
            }
        }
        dfs(v, V, color);
    }
}

int main() {
    int n;
    cin >> n;

    unordered_map<int, vector<pair<int, int>>> V;
    vector<int> color(n + 1, -1);

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        V[u].push_back(make_pair(v, w));
        V[v].push_back(make_pair(u, w));
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
                cout << color[j] << endl;
            }
            break;
        } else {
            dfs(i, V, color);
        }
    }

    return 0;
}

// 
