#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ls(n);
    for (int i = 0; i < n; ++i) {
        cin >> ls[i].first >> ls[i].second;
    }

    sort(ls.begin(), ls.end(), compare);

    int taka = 0, aoki = 0;
    for (int i = 0; i < n; i += 2) {
        taka += ls[i].first;
    }
    for (int i = 1; i < n; i += 2) {
        aoki += ls[i].second;
    }

    cout << taka - aoki << endl;

    return 0;
}
// 
