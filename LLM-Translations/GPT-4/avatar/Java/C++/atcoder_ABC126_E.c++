#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

class UnionFindTree {
public:
    int n;
    vector<int> par, rank;

    UnionFindTree(int n) : n(n), par(n), rank(n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void doIt() {
    int n, m;
    cin >> n >> m;

    UnionFindTree utf(n);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        utf.unite(x, y);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (utf.par[i] == i) {
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main() {
    doIt();
    return 0;
}

// //End of Code
