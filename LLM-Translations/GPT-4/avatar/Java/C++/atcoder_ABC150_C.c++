#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

void permutation(std::vector<std::string> &list, std::string target, std::string ans) {
    if (target.length() <= 1) {
        list.push_back(ans + target);
    } else {
        for (int i = 0; i < target.length(); i++) {
            permutation(list, target.substr(0, i) + target.substr(i + 1), ans + target.at(i));
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> line(2, std::vector<std::string>(1, ""));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            std::string temp;
            std::cin >> temp;
            line[i][0] += temp;
        }
    }
    std::string number = "";
    for (int i = 1; i <= n; i++) {
        number += std::to_string(i);
    }
    std::vector<std::string> listA;
    permutation(listA, number, "");
    int sum = 0;
    for (int j = 0; j < line.size(); j++) {
        for (int i = 0; i < listA.size(); i++) {
            if (listA.at(i) == line[j][0]) {
                if (sum == 0) {
                    sum += i;
                } else {
                    sum -= i;
                }
            }
        }
    }
    std::cout << std::abs(sum) << std::endl;
    return 0;
}

// //End of Code
