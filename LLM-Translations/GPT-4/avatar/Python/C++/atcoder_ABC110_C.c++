#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::string run(std::string s, std::string t) {
    std::map<char, int> counter_s, counter_t;
    for (char c : s) counter_s[c]++;
    for (char c : t) counter_t[c]++;
    std::vector<int> values_s, values_t;
    for (auto& it : counter_s) values_s.push_back(it.second);
    for (auto& it : counter_t) values_t.push_back(it.second);
    std::sort(values_s.begin(), values_s.end());
    std::sort(values_t.begin(), values_t.end());
    if (values_s == values_t) return "Yes";
    else return "No";
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << run(s, t) << std::endl;
    return 0;
}
// End of Code
