#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class codeforces_216_B {
public:
    int count;
    bool seen[100005];
    int path = 0, cycle = 1;
    vector<int> graph[100005];

    int dfs(int child, int par) {
        if (seen[child] == true) return cycle;
        seen[child] = true;
        for (int i = 0; i < graph[child].size(); i++){
            if (graph[child][i] != par) {
                this->count++;
                if (dfs(graph[child][i], child) == cycle) return cycle;
            }
        }
        return path;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    codeforces_216_B ft;
    for (int i = 0; i <= m; i++) {
        ft.seen[i] = false;
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ft.graph[x].push_back(y);
        ft.graph[y].push_back(x);
    }
    int toremove = 0;
    for (int i = 1; i <= m; i++) {
        if (!ft.seen[i]) {
            ft.count = 0;
            if (ft.dfs(i, 0) == ft.cycle) {
                if (ft.count % 2 == 1) toremove++;
            }
        }
    }
    if ((m - toremove) % 2 == 1) toremove++;
    cout << toremove;
    return 0;
} ////End of Code.
