#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = numeric_limits<long long>::max();

    for (int i = 1; i <= static_cast<int>(sqrt(n)) + 1; ++i) {
        if (n % i != 0) {
            continue;
        }
        int j = n / i;
        ans = min(ans, static_cast<long long>(i + j - 2));
    }

    cout << ans << endl;

    return 0;
}
// 
