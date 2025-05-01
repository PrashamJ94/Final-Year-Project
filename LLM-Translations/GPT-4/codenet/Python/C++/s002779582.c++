#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> Hs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> Hs[i];
    }

    int ans = 0;
    int maxH = 0;
    for (int H : Hs) {
        if (maxH <= H) {
            ans += 1;
            maxH = H;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

// 
