#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int K, N;
    std::cin >> K >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    std::vector<int> dist;
    for (int i = 0; i < N - 1; ++i) {
        dist.push_back(A[i + 1] - A[i]);
    }
    dist.push_back(K + A[0] - A[N - 1]);
    int maxv = *std::max_element(dist.begin(), dist.end());
    int total = 0;
    for (int d : dist) {
        total += d;
    }
    std::cout << total - maxv << std::endl;
    return 0;
}
// 
