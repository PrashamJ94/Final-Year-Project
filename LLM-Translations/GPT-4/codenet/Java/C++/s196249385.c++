#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> cumsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    vector<long long> b;
    long long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b.push_back(cumsum[j + 1] - cumsum[i]);
            max = std::max(max, cumsum[j + 1] - cumsum[i]);
        }
    }

    long long mask = 1LL << (63 - __builtin_clzll(max));
    while (mask > 0) {
        vector<long long> tmp;
        for (long long e : b) {
            if ((e & mask) != 0) {
                tmp.push_back(e);
            }
        }

        if (tmp.size() >= k) {
            b = tmp;
        }

        mask >>= 1;
    }

    if (b.size() < k) {
        cout << 0 << endl;
    } else {
        long long ans = -1LL;
        for (long long e : b) {
            ans &= e;
        }

        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}

// 
