cpp
#include<bits/stdc++.h>
using namespace std;
static int n;
vector<vector<pair<int, int>>> g;
vector<int> ans;

void dfs(int to, int color, int parents) {
    int k = 1;
    for (auto e : g[to]) {
        if (e.second == parents) continue;
        if (k == color) k++;
        ans[e.first] = k;
        dfs(e.second, k, to);
        k++;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back({i, b});
        g[b].push_back({i, a});
    }

    ans = vector<int>(n - 1);
    dfs(0, -1, -1);

    int maxColor = 0;
    for (int temp : ans) {
        maxColor = max(maxColor, temp);
    }

    cout << maxColor << "\n";

    for (int c : ans) {
        cout << c << "\n";
    }

    return 0;
}

// //End of Code


