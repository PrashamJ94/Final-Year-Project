#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::vector<int> p_copy(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p_copy[i] = p[i];
    }
    
    std::sort(p.begin(), p.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != p_copy[i]) {
            count += 1;
        }
    }

    if (count == 0 || count == 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
} // 
