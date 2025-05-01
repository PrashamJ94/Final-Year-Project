
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> A(2, std::vector<int>(N));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> ans;

    for (int i = 0; i < N; ++i) {
        int count = 0;
        count = count + std::accumulate(A[0].begin(), A[0].begin() + i + 1, 0) + std::accumulate(A[1].begin() + i, A[1].end(), 0);
        ans.push_back(count);
    }

    std::cout << *max_element(ans.begin(), ans.end()) << std::endl;

    return 0;
}

// 
