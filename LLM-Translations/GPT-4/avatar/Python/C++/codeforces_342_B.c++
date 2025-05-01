#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;

    int d, j = s, t, l , r, k = 1;
    char c;
    string res = "";

    if(s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }

    cin >> t >> l >> r;

    for(int i = 1; j != f; ++i) {
        if(i > t && k < m) {
            cin >> t >> l >> r;
            k++;
        }
        if(i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res += 'X';
        } else {
            res += c;
            j += d;
        }
    }

    cout << res;

    return 0;
}

// End of Code.
