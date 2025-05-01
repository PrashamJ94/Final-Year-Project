#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int stringToInt(const std::string& str) {
    int num;
    std::istringstream(str) >> num;
    return num;
}

int main() {
    int mod = 1000000007;
    std::string input;
    std::getline(std::cin, input);
    int n = stringToInt(input);
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, input);
        as[i] = stringToInt(input);
    }
    std::vector<int> xs = {as[0]};
    for (int j = 1; j < n; j++) {
        int idx = std::lower_bound(xs.begin(), xs.end(), as[j]) - xs.begin();
        if (idx == xs.size()) {
            xs.push_back(as[j]);
        } else {
            xs[idx] = as[j];
        }
    }
    std::cout << xs.size() << std::endl;
}

// 
