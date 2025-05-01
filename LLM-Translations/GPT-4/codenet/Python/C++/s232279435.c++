#include <iostream>
#include <string>
#include <set>

int main() {
    int n;
    std::string s;
    std::cin >> n;
    std::cin >> s;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        std::set<char> x(s.begin(), s.begin() + i + 1);
        std::set<char> y(s.begin() + i + 1, s.end());

        int z = 0;
        for (char w : x) {
            if (y.find(w) != y.end()) {
                z += 1;
            }
        }
        if (z > ans) {
            ans = z;
        }
    }
    std::cout << ans << std::endl;

    return 0;
} // 
