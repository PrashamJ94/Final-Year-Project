#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::map<int, int> map;
    for (int i = 1; i < N + 1; i++) {
        int value;
        std::cin >> value;
        map.insert({i, value});
    }

    std::vector<std::pair<int, int>> sorted_map(map.begin(), map.end());
    std::sort(sorted_map.begin(), sorted_map.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second < b.second;
    });

    std::stringstream output;
    for (const auto &entry : sorted_map) {
        output << entry.first << " ";
    }

    std::cout << output.str() << std::endl;

    return 0;
}
// 
