#include <iostream>
using namespace std;

int main() {
    int N;
    long long ans = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        ans += i * (N / i) * (N / i + 1) / 2;
    }
    cout << ans << endl;
    return 0;
} // End of Code
