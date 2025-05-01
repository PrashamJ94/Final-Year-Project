
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> dp = {-numeric_limits<long long>::max()};
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        num = -num;
        if (num >= dp.back()) {
            dp.push_back(num);
        } else {
            auto idx = upper_bound(dp.begin(), dp.end(), num);
            *idx = num;
        }
    }

    cout << dp.size() - 1 << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}


