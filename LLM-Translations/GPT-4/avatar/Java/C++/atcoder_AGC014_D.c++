#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> g[100005];

int maxMatching(int v, int p) {
    int a = 0, o = 0;
    for (int w : g[v]) {
        if (w == p) continue;
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }
    return 2 * a + min(1, o) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m = maxMatching(0, -1) / 2;
    cout << (2 * m == n ? "Second" : "First") << endl;

    return 0;
}

// //End of Code
