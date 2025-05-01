#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::vector<int> ve, vo;
    for (int i = 0; i < n / 2; ++i) {
        ve.push_back(v[2 * i]);
        vo.push_back(v[2 * i + 1]);
    }
    std::map<int, int> ce, co;
    for (int num : ve) {
        ++ce[num];
    }
    for (int num : vo) {
        ++co[num];
    }

    int ans = n;
    auto ce_most_common = std::max_element(ce.begin(), ce.end(),
                                            [](const auto &a, const auto &b) { return a.second < b.second; });
    auto co_most_common = std::max_element(co.begin(), co.end(),
                                            [](const auto &a, const auto &b) { return a.second < b.second; });

    if (ce_most_common->first != co_most_common->first) {
        ans = n - ce_most_common->second - co_most_common->second;
    } else if (ce.size() == 1 && co.size() == 1) {
        ans = n - ce_most_common->second;
    } else if (ce.size() == 1) {
        co.erase(co_most_common);
        auto co_second_most_common = std::max_element(co.begin(), co.end(),
                                                      [](const auto &a, const auto &b) { return a.second < b.second; });
        ans = n - ce_most_common->second - co_second_most_common->second;
    } else if (co.size() == 1) {
        ce.erase(ce_most_common);
        auto ce_second_most_common = std::max_element(ce.begin(), ce.end(),
                                                      [](const auto &a, const auto &b) { return a.second < b.second; });
        ans = n - ce_second_most_common->second - co_most_common->second;
    } else {
        ce.erase(ce_most_common);
        co.erase(co_most_common);
        auto ce_second_most_common = std::max_element(ce.begin(), ce.end(),
                                                      [](const auto &a, const auto &b) { return a.second < b.second; });
        auto co_second_most_common = std::max_element(co.begin(), co.end(),
                                                      [](const auto &a, const auto &b) { return a.second < b.second; });
        ans = std::min(n - ce_most_common->second - co_second_most_common->second,
                       n - ce_second_most_common->second - co_most_common->second);
    }
    std::cout << ans << std::endl;
    return 0;
}
// 
