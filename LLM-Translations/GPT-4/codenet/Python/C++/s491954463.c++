#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a, b;
    for (int i = 0; i < m; i++) {
        int a1, b1;
        std::cin >> a1 >> b1;
        a.push_back(a1);
        b.push_back(b1);
    }

    for (int i = 1; i <= n; i++) {
        std::cout << std::count(a.begin(), a.end(), i) + std::count(b.begin(), b.end(), i) << std::endl;
    }

    return 0;
}
// 
