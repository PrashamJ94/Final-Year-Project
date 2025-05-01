#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    int mod = 998244353;

    if (D[0] != 0) {
        cout << 0 << endl;
        return;
    }

    map<int, int> cnt;
    for (int d : D) {
        cnt[d]++;
    }

    if (cnt[0] > 1) {
        cout << 0 << endl;
        return;
    }

    long long res = 1;

    for (int i = 1; i <= *max_element(D.begin(), D.end()); i++) {
        if (cnt[i - 1] == 1) {
            continue;
        }
        long long temp = 1;
        for (int j = 0; j < cnt[i]; j++) {
            temp = (temp * cnt[i - 1]) % mod;
        }
        res = (res * temp) % mod;
    }

    cout << res << endl;
}

int main() {
    solve();
    return 0;
}

// 
