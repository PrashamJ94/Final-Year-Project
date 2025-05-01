
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> XS(N);
    for (int i = 0; i < N; i++) {
        std::cin >> XS[i];
    }

    int m = std::numeric_limits<int>::max();
    for (int i = 1; i <= 100; i++) {
        int c = 0;
        for (int x : XS) {
            c += (x - i) * (x - i);
        }
        if (m > c) {
            m = c;
        }
    }

    std::cout << m << std::endl;

    return 0;
}
// 


