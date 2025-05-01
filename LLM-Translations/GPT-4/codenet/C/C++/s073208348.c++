#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

// Edge information
struct Edge {
    ll s, g, c;
};

// Graph structure
struct Graph {
    int vcnt, ecnt;
    vector<Edge> e;
    vector<int> id;

    Graph(int n) : vcnt(n), ecnt(2 * n - 2), e(2 * n - 2), id(n) {}
};

bool esort(const Edge &a, const Edge &b) {
    if (a.s < b.s) return true;
    if (a.s > b.s) return false;
    return a.g < b.g;
}

Graph readgraph() {
    ll n;
    cin >> n;
    Graph g(n);
    for (ll i = 0; i < n - 1; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        g.e[2 * i] = {x, y, c};
        g.e[2 * i + 1] = {y, x, c};
    }
    sort(g.e.begin(), g.e.end(), esort);

    int p = 0;
    for (int i = 0; i < g.vcnt; i++) {
        while (p < g.ecnt && g.e[p].s < i) p++;
        g.id[i] = p;
    }
    g.id.push_back(g.ecnt); // sentinel
    return g;
}

vector<int> tyokkeitemp;

void tyokkeidfs(const Graph &g, ll s) {
    for (int i = g.id[s]; i < g.id[s + 1]; i++) {
        if (tyokkeitemp[g.e[i].g] == 0) {
            tyokkeitemp[g.e[i].g] = tyokkeitemp[s] + g.e[i].c;
            tyokkeidfs(g, g.e[i].g);
        }
    }
}

int tyokkei(const Graph &g) {
    tyokkeitemp.assign(g.vcnt + 10, 0);
    tyokkeitemp[0] = 1;
    tyokkeidfs(g, 0);

    int M = 0, Mi;
    for (int i = 0; i < g.vcnt; i++) {
        if (tyokkeitemp[i] > M) {
            M = tyokkeitemp[i];
            Mi = i;
        }
    }

    fill(tyokkeitemp.begin(), tyokkeitemp.end(), 0);
    tyokkeitemp[Mi] = 1;
    tyokkeidfs(g, Mi);

    for (int i = 0; i < g.vcnt; i++) M = max(M, tyokkeitemp[i]);
    return M - 1;
}

int main() {
    Graph g = readgraph();
    cout << tyokkei(g) << endl;
}

// 
