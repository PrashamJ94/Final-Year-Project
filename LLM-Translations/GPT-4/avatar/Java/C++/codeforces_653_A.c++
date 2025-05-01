#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::set<int> distinct(a.begin(), a.end());
    a.assign(distinct.begin(), distinct.end());
    std::sort(a.begin(), a.end());
    
    bool found = false;
    for (int i = 0; i < a.size(); i++) {
        if (i + 1 < a.size() && i + 2 < a.size()) {
            if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
                found = true;
            }
        }
    }
    
    std::cout << (found ? "YES" : "NO") << std::endl;
    return 0;
}

// //End of Code
