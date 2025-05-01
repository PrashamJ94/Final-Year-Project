#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::string c;
    std::cin >> c;

    int num_w = std::count(c.begin(), c.end(), 'W');
    int num_r = N - num_w;

    std::string comp = std::string(num_r, 'R') + std::string(num_w, 'W');
    int ans = 0;
    for (int i = 0; i < num_r; i++) {
        if (c[i] != comp[i]) {
            ans++;
        }
    }

    ans = std::min({num_w, num_r, ans});
    std::cout << ans << std::endl;

    return 0;
} // 
