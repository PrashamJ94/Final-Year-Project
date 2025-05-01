#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Comparator for custom sorting
struct customCompare {
    bool operator()(const pii &a, const pii &b) {
        return a.second < b.second;
    }
};

int L, R, top, bottom;

void solve() {
    int t = 1;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        if (n == m) {
            cout << 0 << endl;
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            cout << min(m - n, n) << endl;
            continue;
        }
        cout << min(m - n, n) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
// 
