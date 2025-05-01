#include<bits/stdc++.h>
using namespace std;

bool help(int a, int b, vector<int> &l) {
    vector<vector<int>> tot;
    for (int i = 0; i < b; i++) {
        vector<int> temp(l.begin() + i * a, l.begin() + i * a + a);
        tot.push_back(temp);
    }
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if (sum == b) return true;
    }
    return false;
}

void solve() {
    vector<pair<int, int>> tot;
    string x;
    cin >> x;
    vector<int> s;
    for (char i : x) {
        if (i == 'O') s.push_back(0);
        else s.push_back(1);
    }
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) tot.emplace_back(12 / i, i);
        }
    }
    cout << tot.size() << ' ';
    sort(tot.begin(), tot.end());
    for (auto & i : tot) {
        cout << i.first << 'x' << i.second << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// End of Code.
