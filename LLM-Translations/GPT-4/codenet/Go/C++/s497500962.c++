#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>

int main() {
    int R, G, B, N;
    std::cin >> R >> G >> B >> N;

    int ans = 0;
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            int tmp = N - R * x - G * y;
            if (tmp >= 0 && tmp % B == 0) {
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

// 
