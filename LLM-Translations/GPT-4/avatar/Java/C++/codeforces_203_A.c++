#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    int first, second;
    bool ok = false;
    for (int i = 0; i < t; i++) {
        first = a - (da * i);
        for (int j = 0; j < t; j++) {
            second = b - (db * j);
            if (second + first == x || second == x || first == x || x == 0) {
                ok = true;
                break;
            }
        }
    }

    if (ok)
        cout << "YES";
    else
        cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

// //End of Code.
