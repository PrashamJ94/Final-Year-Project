#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> ls(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ls[i];
    }

    std::map<std::string, int> c;
    for (const std::string &s : ls) {
        ++c[s];
    }

    int count = std::max_element(c.begin(), c.end(),
        [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
            return a.second < b.second;
        })->second;

    std::vector<std::string> ans;
    for (const auto &p : c) {
        if (p.second == count) {
            ans.push_back(p.first);
        }
    }

    std::sort(ans.begin(), ans.end());
    for (const std::string &s : ans) {
        std::cout << s << std::endl;
    }

    return 0;
} // 
