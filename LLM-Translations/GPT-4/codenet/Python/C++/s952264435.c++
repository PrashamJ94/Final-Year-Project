#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i];
    }

    int A_sum = std::accumulate(A.begin(), A.end(), 0);

    std::cout << (N - A_sum >= 0 ? N - A_sum : -1) << std::endl;

    return 0;
}
// 
