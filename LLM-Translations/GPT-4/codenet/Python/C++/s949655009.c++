
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::string strn = std::to_string(n);
    std::vector<std::string> shichigolist = {"3", "5", "7"};
    std::vector<std::vector<std::string>> shichigo(strn.size());

    for (int i = 0; i < strn.size(); ++i) {
        if (i == 0) {
            for (const std::string& j : shichigolist) {
                shichigo[i].push_back(j);
            }
        } else {
            for (const std::string& j : shichigo[i - 1]) {
                for (const std::string& k : shichigolist) {
                    shichigo[i].push_back(j + k);
                }
            }
        }
    }

    int target = strn.size() - 1;
    for (int i = 0; i < strn.size(); ++i) {
        for (auto it = shichigo[i].begin(); it != shichigo[i].end();) {
            if (i == target) {
                if (std::stoi(*it) > n) {
                    it = shichigo[target].erase(it);
                } else if (std::count(it->begin(), it->end(), '3') == 0 || std::count(it->begin(), it->end(), '5') == 0 || std::count(it->begin(), it->end(), '7') == 0) {
                    it = shichigo[target].erase(it);
                } else {
                    ++it;
                }
            } else {
                if (std::count(it->begin(), it->end(), '3') == 0 || std::count(it->begin(), it->end(), '5') == 0 || std::count(it->begin(), it->end(), '7') == 0) {
                    it = shichigo[i].erase(it);
                } else {
                    ++it;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < strn.size(); ++i) {
        result += shichigo[i].size();
    }

    std::cout << result << std::endl;

    return 0;
}
// 


