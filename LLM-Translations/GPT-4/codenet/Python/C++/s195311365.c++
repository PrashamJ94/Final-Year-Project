#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    if (s.length() == 2) {
        std::cout << s << std::endl;
    } else {
        std::reverse(s.begin(), s.end());
        std::cout << s << std::endl;
    }

    return 0;
} // 
