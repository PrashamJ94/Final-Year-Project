
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> ope(m);
    for (int i = 0; i < m; i++) {
        cin >> ope[i].first >> ope[i].second;
    }
    sort(ope.begin(), ope.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < ope[j].second) {
            a[i] = ope[j].second;
            ope[j].first -= 1;
            if (ope[j].first == 0) {
                j += 1;
                if (j == ope.size()) {
                    break;
                }
            }
        } else {
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}

// 
