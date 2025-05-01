#include <iostream>
using namespace std;

int main() {
    long long mod = 1e9 + 7;
    long long N, A, B;
    cin >> N >> A >> B;
    long long ans = 0;
    long long rep = N / (A + B);
    ans += rep * A;
    long long res = N - rep * (A + B);
    ans += min(res, A);
    cout << ans << endl;
    return 0;
}

// End of Code.
