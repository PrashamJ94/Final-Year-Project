
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main() {
    int n, m;
    std::cin >> n;
    std::cin.ignore();
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> a_str = split(line, ' ');
    std::set<int> a;
    for (const auto &str : a_str) {
        a.insert(std::stoi(str));
    }

    std::cin >> m;
    std::cin.ignore();
    std::getline(std::cin, line);
    std::vector<std::string> b_str = split(line, ' ');
    std::vector<int> result;
    for (const auto &str : b_str) {
        int num = std::stoi(str);
        if (a.find(num) != a.end()) {
            a.erase(num);
        } else {
            a.insert(num);
        }
    }

    std::copy(a.begin(), a.end(), std::back_inserter(result));
    std::sort(result.begin(), result.end());
    for (const auto &num : result) {
        std::cout << num << std::endl;
    }

    return 0;
}


