#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class atcoder_AGC027_B {
    int INF = numeric_limits<int>::max();
    public:
        void solve();
};

void atcoder_AGC027_B::solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> x(N), xsum(N + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> x[i];
        xsum[i + 1] = xsum[i] + x[i];
    }

    long long ans = X * N + 5 * xsum[N];
    for (int i = 1; i < N; i++) {
        long long cost = X * i + 5 * (xsum[N] - xsum[N - i]);
        for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
            if (cost > ans) {
                break;
            }
            cost += j * (xsum[k] - xsum[max(k - i, 0)]);
        }
        ans = min(ans, cost);
    }
    cout << ans + N * X << endl;
}

int main() {
    atcoder_AGC027_B solver;
    solver.solve();
    return 0;
}

// //End of Code
