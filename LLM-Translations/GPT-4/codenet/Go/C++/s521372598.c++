#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> as[i];
    }

    std::vector<int> xs(n);
    for (int i = 0; i < n; ++i) {
        xs[i] = as[i] - i + 1;
    }
    sort(xs.begin(), xs.end());

    int b = xs[n / 2];
    int ans = 0;
    for (int x : xs) {
        ans += abs(x - b);
    }
    std::cout << ans << std::endl;
}

int main() {
    solve();
    return 0;
}

// 
