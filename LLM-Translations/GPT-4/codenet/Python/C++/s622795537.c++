#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> arr;

    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        if (arr.find(s) == arr.end()) {
            arr[s] = 1;
        } else {
            arr[s]++;
        }
    }

    int max_count = 0;
    for (const auto &entry : arr) {
        max_count = std::max(max_count, entry.second);
    }

    std::vector<std::string> dic;
    for (const auto &entry : arr) {
        if (entry.second == max_count) {
            dic.push_back(entry.first);
        }
    }

    std::sort(dic.begin(), dic.end());
    for (const auto &s : dic) {
        std::cout << s << std::endl;
    }

    return 0;
}
// 
