
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>

int main() {
    int X, N;
    std::cin >> X >> N;
    std::vector<int> p(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> p[i];
    }

    std::sort(p.begin(), p.end());

    std::map<int, std::vector<int>> candidates;
    
    for (int i = -1; i <= 102; ++i) {
        if (std::find(p.begin(), p.end(), i) != p.end()) {
            continue;
        }

        int diff = std::abs(X - i);
        
        if (candidates.find(diff) == candidates.end()) {
            candidates[diff] = std::vector<int>{i};
        } else {
            candidates[diff].push_back(i);
        }
    }

    int smallest = std::numeric_limits<int>::max();

    for (const auto& pair : candidates) {
        if (pair.first < smallest) {
            smallest = pair.first;
        }
    }

    int minNum = *std::min_element(candidates[smallest].begin(), candidates[smallest].end());

    std::cout << minNum << std::endl;

    return 0;
}


