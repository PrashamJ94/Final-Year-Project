#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    int q;
    std::cin >> s >> q;
    std::vector<std::vector<std::string>> qs(q);
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::string temp;
            std::cin >> temp;
            qs[i].push_back(temp);
        }
    }
    bool n = false;
    std::string left, right;
    for (auto operation : qs) {
        if (operation[0] == "1") {
            n = !n;
        }
        if (operation[0] == "2") {
            std::string t = operation[0];
            int f = std::stoi(operation[1]);
            std::string c = operation[2];
            if (n) {
                f = (f != 1) ? 1 : 2;
            }
            if (f == 1) {
                left = c + left;
            } else if (f == 2) {
                right += c;
            }
        }
    }
    s = left + s + right;
    std::cout << (n ? std::string(s.rbegin(), s.rend()) : s) << std::endl;
    return 0;
}
// 
