
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    for (std::size_t i = 0; i < s.length(); ++i) {
        if (std::count(s.begin() + i + 1, s.end(), s[i]) > 0) {
            std::cout << "no" << std::endl;
            return 0;
        }
    }

    std::cout << "yes" << std::endl;
    return 0;
}

// 
