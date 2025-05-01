#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::vector<int> a(5);
    std::map<int, int> dic;

    for (int i = 0; i < 5; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < 5; ++i) {
        if (a[i] % 10 == 0) {
            dic[i] = 0;
        } else {
            dic[i] = a[i] % 10 - 10;
        }
    }

    int min_num = std::min_element(dic.begin(), dic.end(), [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
        return lhs.second < rhs.second;
    })->first;
    int a_sum = 0;
    for (const auto& elem : a) {
        a_sum += elem;
    }
    dic.erase(min_num);
    int dic_sum = 0;
    for (const auto& elem : dic) {
        dic_sum += elem.second;
    }
    std::cout << std::abs(dic_sum) + a_sum << std::endl;

    return 0;
}
// 
