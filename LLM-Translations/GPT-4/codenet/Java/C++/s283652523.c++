#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <iterator>
#include <sstream>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long ans = 0, sum = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
// 
