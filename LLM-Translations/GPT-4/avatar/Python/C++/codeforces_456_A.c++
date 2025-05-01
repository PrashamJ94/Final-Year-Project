#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector< pair<int, int> > m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i].first >> m[i].second;
    }
    sort(m.begin(), m.end(), greater< pair<int, int> >());
    pair<int, int> a = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i].second > a.second) {
            cout << "Happy Alex";
            return 0;
        }
        a = m[i];
    }
    cout << "Poor Alex";
    return 0;
} // End of Code
