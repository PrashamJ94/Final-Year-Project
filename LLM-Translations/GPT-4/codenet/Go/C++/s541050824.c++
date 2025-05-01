#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <limits>
#include <cmath>

int64_t max(int64_t x, int64_t y) {
    return (x > y) ? x : y;
}

int64_t min(int64_t x, int64_t y) {
    return (x < y) ? x : y;
}

int64_t divUp(int64_t x, int64_t y) {
    return (x + y - 1) / y;
}

void solve() {
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> T(N), A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> T[i] >> A[i];
    }
    int64_t t = T[0], a = A[0];
    for (int i = 1; i < N; i++) {
        int64_t r = max(divUp(t, T[i]), divUp(a, A[i]));
        t = T[i] * r;
        a = A[i] * r;
    }
    std::cout << t + a << std::endl;
}

int main() {
    solve();
    return 0;
}

// 
