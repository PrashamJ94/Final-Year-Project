#include <iostream>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;

    for (int i = 1; i < n + 1; i++) {
        ans += static_cast<long long>(i) * (static_cast<long long>(n) / static_cast<long long>(i)) * ((static_cast<long long>(n) / static_cast<long long>(i)) + 1) / 2;
    }

    cout << ans << endl;
    return 0;
} // //End of Code.
