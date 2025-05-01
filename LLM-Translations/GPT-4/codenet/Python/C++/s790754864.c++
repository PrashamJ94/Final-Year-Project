
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;

long long fact(int n, int r) {
    return tgamma(n + 1) / (tgamma(n - r + 1) * tgamma(r + 1));
}

int main() {
    int N, K;
    cin >> N >> K;
    int R = N - K;

    for (int i = 1; i <= K; ++i) {
        long long ans;
        if (N - K + 1 < i) {
            ans = 0;
        } else {
            ans = fact(R + 1, i) * fact(K - 1, i - 1);
        }
        cout << ans % mod << endl;
    }

    return 0;
}


