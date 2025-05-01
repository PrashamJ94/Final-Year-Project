#include <iostream>
#include <vector>
#include <algorithm>

const int size = 100001;

int main() {
    int n, t, l, r;
    std::vector<int> mem(size, 0);
    std::cin >> n;
    std::cin >> t;
    for (int i = 0; i < n; i++) {
        std::cin >> l;
        std::cin >> r;
        mem[l] += 1;
        mem[r] -= 1;
    }
    int ans = mem[0];
    for (int i = 1; i < t + 1; i++) {
        mem[i] += mem[i - 1];
        ans = std::max(ans, mem[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}

// 
