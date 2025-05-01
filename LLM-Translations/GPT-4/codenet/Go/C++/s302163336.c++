#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int n, m, ai, bi;
    std::cin >> n >> m;
    std::vector<int> h(n);
    std::vector<bool> good(n, true);
    for(int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    for(int i = 0; i < m; i++) {
        std::cin >> ai >> bi;
        ai--; bi--;
        if(h[ai] > h[bi]) {
            good[bi] = false;
        } else if(h[ai] < h[bi]) {
            good[ai] = false;
        } else {
            good[ai] = false;
            good[bi] = false;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(good[i]) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

// 
