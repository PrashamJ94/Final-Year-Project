#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            g[u][v] = 1;
        }
    }

    vector<int> d(n + 1, -1);
    queue<int> que;
    que.push(1);
    d[1] = 0;

    while (!que.empty()) {
        int top = que.front();
        que.pop();
        for (int j = 1; j <= n; j++) {
            if (g[top][j] == 1 && d[j] == -1) {
                que.push(j);
                d[j] = d[top] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << d[i] << endl;
    }

    return 0;
}

// 
