#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    int a;

    for (int i = 1; i < N; i++) {
        std::cin >> a;
        v[a - 1]++;
    }

    for (const auto &e : v) {
        std::cout << e << std::endl;
    }
    return 0;
}

// 
