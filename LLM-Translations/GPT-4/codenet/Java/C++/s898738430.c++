#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n-1; i++) {
        if(a[i] != std::min(a[i-1], std::min(a[i], a[i+1]))
                && a[i] != std::max(a[i-1], std::max(a[i], a[i+1]))){
            ans++;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}

// 
