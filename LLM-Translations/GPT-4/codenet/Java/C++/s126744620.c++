#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for(int i = 0 ; i < n ; i++) std::cin >> a[i];
    std::vector<int> x(200010, 0);
    for(int i = 0 ; i < n ; i++) {
        x[a[i] - 1]++;
    }
    std::sort(x.begin(), x.end());
    int ans = 0;
    for(int i = 0 ; i <= 200010 - k - 1 ; i++) {
        ans += x[i];
    }
    std::cout << ans;
    return 0;
}

// 
