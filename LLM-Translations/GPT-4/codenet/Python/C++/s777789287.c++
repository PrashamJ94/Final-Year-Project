#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.rbegin(), a.rend());
    double s = std::accumulate(a.begin(), a.end(), 0) / (4.0 * m);

    if (a[m - 1] >= s) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
} // 
