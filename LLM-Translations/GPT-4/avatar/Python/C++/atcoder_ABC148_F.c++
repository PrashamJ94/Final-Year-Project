#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 1000000007
#define MAXN 200005

vector<int> g[MAXN];
int ta_dist[MAXN], ao_dist[MAXN];
int n, ta, ao;

void ta_dfs(int node) {
    for(int v : g[node]) {
        if(ta_dist[v] != -1) continue;
        ta_dist[v] = ta_dist[node] + 1;
        ta_dfs(v);
    }
}

void ao_dfs(int node) {
    for(int v : g[node]) {
        if(ao_dist[v] != -1) continue;
        ao_dist[v] = ao_dist[node] + 1;
        ao_dfs(v);
    }
}

int main() {
    cin >> n >> ta >> ao;
    ta--; ao--;
    memset(ta_dist, -1, sizeof(ta_dist));
    memset(ao_dist, -1, sizeof(ao_dist));
    ta_dist[ta] = 0;
    ao_dist[ao] = 0;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ao_dfs(ao);
    ta_dfs(ta);
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(ta_dist[i] > ao_dist[i]) continue;
        res = max(res, ao_dist[i]);
    }
    cout << res - 1 << endl;
    return 0;
}

// End of Code.
