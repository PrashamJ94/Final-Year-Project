#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, L;
    std::cin >> N >> L;
    std::vector<int> aji;
    for (int i = 1; i <= N; ++i) {
        aji.push_back(L + i - 1);
    }
    if (*std::min_element(aji.begin(), aji.end()) >= 0) {
        aji.erase(std::min_element(aji.begin(), aji.end()));
    } else if (*std::max_element(aji.begin(), aji.end()) <= 0) {
        aji.erase(std::max_element(aji.begin(), aji.end()));
    } else {
        aji.erase(std::min_element(aji.begin(), aji.end(), [](int a, int b) {
            return std::abs(a) < std::abs(b);
        }));
    }
    int sum = 0;
    for (int x : aji) {
        sum += x;
    }
    std::cout << sum << std::endl;

    return 0;
}

// 
