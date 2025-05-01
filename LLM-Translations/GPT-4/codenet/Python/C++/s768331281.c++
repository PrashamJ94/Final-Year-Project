#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int N, L;
    std::cin >> N >> L;
    std::vector<std::string> S(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> S[i];
    }
    std::sort(S.begin(), S.end());
    for (const auto& str : S) {
        std::cout << str;
    }
    std::cout << std::endl;
    // 
    return 0;
}
