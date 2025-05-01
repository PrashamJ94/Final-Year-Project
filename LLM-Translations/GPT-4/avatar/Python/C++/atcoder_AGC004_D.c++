#include<bits/stdc++.h>
using namespace std;

pair<int, int> dfs(vector<set<int>>& links, int n, int k, int v, int p) {
    int height_from_leaf = 0;
    int cut_count = 0;
    for(auto u : links[v]) {
        if(u == 0) continue;
        pair<int, int> result = dfs(links, n, k, u, v);
        height_from_leaf = max(height_from_leaf, result.first);
        cut_count += result.second;
    }
    height_from_leaf += 1;
    if(p != 0 && height_from_leaf == k) {
        height_from_leaf = 0;
        cut_count += 1;
    }
    return make_pair(height_from_leaf, cut_count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> aaa(n);
    for(int i = 0; i < n; i++) cin >> aaa[i];
    vector<set<int>> links(n);
    for(int i = 0; i < n; i++) {
        aaa[i]--;
        links[aaa[i]].insert(i);
    }
    pair<int, int> result = dfs(links, n, k, 0, 0);
    int ans = result.second;
    if(aaa[0] != 1) ans += 1;
    cout << ans << "\n";
    return 0;
} // End of Code
