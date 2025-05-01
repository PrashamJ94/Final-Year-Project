
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, l;
    std::cin >> n >> l;
    std::vector<std::string> S(n);
    for (int a = 0; a < n; a++) {
        std::cin >> S[a];
    }
    std::sort(S.begin(), S.end());
    for (const std::string &s : S) {
        std::cout << s;
    }
    std::cout << std::endl;

    return 0;
}


