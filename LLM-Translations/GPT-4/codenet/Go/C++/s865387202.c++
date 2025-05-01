#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstdio>

struct city {
    int prefecture;
    int position;
    int year;
};

bool compare(const city &a, const city &b) {
    return a.year < b.year;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, std::vector<city>> h;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        h[x].push_back({x, i, y});
    }

    std::vector<std::string> results(m);

    for (auto &kv : h) {
        std::sort(kv.second.begin(), kv.second.end(), compare);
        for (int idx = 0; idx < kv.second.size(); ++idx) {
            char buf[13];
            snprintf(buf, sizeof(buf), "%06d%06d", kv.second[idx].prefecture, idx + 1);
            results[kv.second[idx].position] = buf;
        }
    }
    for (const auto &result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}

// 
