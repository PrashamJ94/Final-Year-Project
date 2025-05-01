#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::sort(A.rbegin(), A.rend());
    int S = std::accumulate(A.begin(), A.end(), 0);
    for (int a : A) {
        if (--M < 0) break;
        if (static_cast<double>(a) / S < 1.0 / (4 * M) - 1e-9) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}

// 
