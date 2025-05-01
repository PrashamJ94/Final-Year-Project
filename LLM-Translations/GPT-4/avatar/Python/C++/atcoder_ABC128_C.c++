
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iterator>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> li(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        li[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> li[i][j];
        }
    }
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    set<int> q;
    for (const auto &l : li) {
        q.insert(l.begin(), l.end());
    }
    set<int> v;
    for (int i = 1; i <= n; i++) {
        if (q.find(i) == q.end()) {
            v.insert(i);
        }
    }
    int ans = 0;
    for (int i = 0; i <= q.size(); i++) {
        vector<int> s(q.begin(), q.end());
        do {
            bool valid = true;
            for (int j = 0; j < m; j++) {
                int count = 0;
                for (int l : li[j]) {
                    if (find(s.begin(), s.begin() + i, l) != s.begin() + i) {
                        count++;
                    }
                }
                if (count % 2 != p[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans += pow(2, v.size());
            }
        } while (next_permutation(s.begin(), s.end()));
    }
    cout << ans << endl;
    return 0;
}
// End of Code


Please note that the C++ code might not perform well for large inputs because it uses a brute force approach to check all possible combinations of switches. This is due to the lack of a built-in combinations generator in C++, unlike Python's itertools.
