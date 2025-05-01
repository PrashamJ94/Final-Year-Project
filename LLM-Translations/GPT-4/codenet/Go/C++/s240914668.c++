#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = i, r = i + 1;
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }
        ans++;
        i = r;
    }
    std::cout << ans << std::endl;

    return 0;
}
// 
