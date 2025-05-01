#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
#include <iterator>

using namespace std;

int inf = 1e14;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    copy(a.begin(), a.end(), v.begin());
    int ans = inf;
    for (int k = 0; k < n; k++) {
        int kans = 0;
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                v[i] = min(v[i], a[n + i - k]);
            } else {
                v[i] = min(v[i], a[i - k]);
            }
            kans += v[i];
        }
        ans = min(ans, kans + k * x);
    }

    cout << ans << endl;

    return 0;
}
// 
