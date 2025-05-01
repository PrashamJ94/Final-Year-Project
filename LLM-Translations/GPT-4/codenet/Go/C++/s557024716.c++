#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> duplicatePatterns(vector<int> &elems, int k) {
    if (k == 0) {
        return {{}};
    }

    vector<vector<int>> res;
    vector<vector<int>> smaller = duplicatePatterns(elems, k - 1);
    for (const auto &p : smaller) {
        for (int e : elems) {
            res.push_back(p);
            res.back().push_back(e);
        }
    }

    return res;
}

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    vector<int> elems = {0, 1, 2, 3};
    vector<vector<int>> patterns = duplicatePatterns(elems, k);

    for (const auto &P : patterns) {
        int r = a, g = b, b = c;
        for (int i = 0; i < P.size(); i++) {
            if (P[i] == 0) {
                continue;
            } else if (P[i] == 1) {
                r *= 2;
            } else if (P[i] == 2) {
                g *= 2;
            } else if (P[i] == 3) {
                b *= 2;
            }
        }

        if (g > r && b > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
// 
