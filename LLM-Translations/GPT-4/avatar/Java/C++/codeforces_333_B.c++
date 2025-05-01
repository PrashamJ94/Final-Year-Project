#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> bannedRows, bannedCols;
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        if (r > 1 && r < n) {
            bannedRows.insert(r);
        }
        if (c > 1 && c < n) {
            bannedCols.insert(c);
        }
    }

    int answer = (n - 2) * 2;
    answer -= bannedRows.size();
    answer -= bannedCols.size();
    if (n % 2 != 0) {
        int mid = (n + 1) / 2;
        if (bannedRows.find(mid) == bannedRows.end() && bannedCols.find(mid) == bannedCols.end()) {
            answer--;
        }
    }

    cout << answer << endl;

    return 0;
}
// //End of Code
