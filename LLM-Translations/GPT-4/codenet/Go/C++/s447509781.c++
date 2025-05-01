#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int64_t> s(n);
    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    std::vector<bool> u(n);
    int64_t m = 0, f = 0;
    for (int c = 1; c < n - 1; c++) {
        f = 0;
        for (int k = 0; c < n - 1 - k * c; k++) {
            u[k * c] = true;
            if (u[n - 1 - k * c]) { break; }
            f += s[n - 1 - k * c] + s[k * c];
            if (m < f) { m = f; }
        }
        for (int k = 0; k * c < n - 1; k++) { u[k * c] = false; }
    }
    std::cout << m << std::endl;
    return 0;
}
// 
