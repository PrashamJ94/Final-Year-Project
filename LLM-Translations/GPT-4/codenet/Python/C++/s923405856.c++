#include <iostream>
#include <algorithm>
#include <climits>

int main() {
    while (true) {
        int n;
        std::cin >> n;

        if (n == 0) {
            break;
        }

        int res = INT_MIN;
        int s = 0;
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            s = std::max(s + a, a);
            res = std::max(s, res);
        }

        std::cout << res << std::endl;
    }
    return 0;
} // 
