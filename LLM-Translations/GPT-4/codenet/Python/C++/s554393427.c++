
#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<double, std::string>> mo;
    for (int i = 0; i < N; ++i) {
        double x;
        std::string u;
        std::cin >> x >> u;
        mo.push_back(std::make_pair(x, u));
    }

    double okz = 0;
    for (std::pair<double, std::string> &i : mo) {
        if (i.second == "JPY") {
            okz += i.first;
        } else {
            okz += i.first * 380000;
        }
    }

    std::cout << okz << std::endl;
    return 0;
}

// 
