
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

const int mod = 1000000007;
const int INF = 1000000007;

void permute(vector<int> &a, int l, int r, vector<vector<int>> &perms) {
    if (l == r) {
        perms.push_back(a);
    } else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            permute(a, l + 1, r, perms);
            swap(a[l], a[i]); // backtrack
        }
    }
}

vector<vector<int>> permutations(vector<int> &a) {
    vector<vector<int>> perms;
    permute(a, 0, a.size() - 1, perms);
    return perms;
}

int main() {
    int n, m, R;
    cin >> n >> m >> R;

    vector<int> rs(R);
    for (int i = 0; i < R; i++) {
        cin >> rs[i];
        rs[i]--;
    }

    vector<vector<int>> costs(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        costs[i][i] = 0;
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // Warshall-Floyd algorithm to compute shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    // Try all permutations of visiting order
    vector<vector<int>> perms = permutations(rs);
    int ans = INF;
    for (const auto &perm : perms) {
        int tmp = 0;
        for (size_t j = 1; j < perm.size(); j++) {
            int from = perm[j - 1];
            int to = perm[j];
            tmp += costs[from][to];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}


