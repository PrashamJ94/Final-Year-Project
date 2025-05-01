#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<std::pair<int, int>> problems(q);
    for(int i = 0; i < q; i++) {
        std::cin >> problems[i].first >> problems[i].second;
    }
    std::vector<int> cumsum(n + 1, 0);
    for(int i = 1; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + (s.substr(i - 1, 2) == "AC" ? 1 : 0);
    }
    for(auto lr : problems) {
        std::cout << cumsum[lr.second] - cumsum[lr.first - 1] << std::endl;
    }
    return 0;
}

End of Code.
