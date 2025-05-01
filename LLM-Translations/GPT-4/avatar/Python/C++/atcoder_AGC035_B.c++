#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<set<int>> edges(N);
    vector<int> degs(N, 0), parity(N, 0);
    vector<bool> flag(N, false);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].insert(b);
        edges[b].insert(a);
        degs[a]++;
        degs[b]++;
    }
    if (M % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for (int i = 0; i < N; i++) {
        Q.push(make_pair(degs[i], i));
    }
    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        if (flag[u]) continue;
        flag[u] = true;
        int i = 0;
        for (auto it = edges[u].begin(); it != edges[u].end(); ++it, ++i) {
            int v = *it;
            edges[v].erase(u);
            if (parity[u] != 0 && i == 0) {
                cout << u + 1 << " " << v + 1 << endl;
                parity[u] = 1 - parity[u];
            } else {
                cout << v + 1 << " " << u + 1 << endl;
                parity[v] = 1 - parity[v];
            }
            degs[v]--;
            Q.push(make_pair(degs[v], v));
        }
    }
    return 0;
}
// End of Code


Note: This C++ code is using Standard Template Library (STL) data structures such as vector, set, and priority_queue. Also, the input and output are done using standard input/output streams (cin/cout).
