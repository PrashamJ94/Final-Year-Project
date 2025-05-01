#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> gate_cond(m, std::vector<int>(2));
    for (int i = 0; i < m; ++i) {
        std::cin >> gate_cond[i][0] >> gate_cond[i][1];
    }

    int max_under_th = -1;
    int min_upper_th = 1000000;
    for (const auto &l : gate_cond) {
        max_under_th = std::max(max_under_th, l[0]);
        min_upper_th = std::min(min_upper_th, l[1]);
    }

    if (min_upper_th - max_under_th >= 0) {
        std::cout << (min_upper_th - max_under_th + 1) << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
} // 
