#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> x(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    std::reverse(x.begin(), x.end());
    for(int i = 0; i < n; ++i) {
        std::cout << x[i] << " ";
    }
    return 0;
} // 
