#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int main() {
    int N, M;
    int ans = 0;
    std::cin >> N >> M;
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        ans += (N - 2) * (M - 2);
    } else {
        ans += (N * M) - 2;
    }

    std::cout << ans << std::endl;
    return 0;
}

/*  ----------------------------------------  */

int max(int x, int y) {
    return std::max(x, y);
}

int min(int x, int y) {
    return std::min(x, y);
}

int pow(int x, int y) {
    return std::pow(x, y);
}

int abs(int x) {
    return std::abs(x);
}

int floor(int x) {
    return std::floor(x);
}

class SortBy {
public:
    bool operator() (int i, int j) {
        return abs(i) < abs(j);
    }
};

// 
