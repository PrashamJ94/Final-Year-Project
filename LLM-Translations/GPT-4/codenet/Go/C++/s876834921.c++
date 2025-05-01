
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    while (s.find("dream") != std::string::npos) {
        s.replace(s.find("dream"), 5, "D");
    }
    while (s.find("erase") != std::string::npos) {
        s.replace(s.find("erase"), 5, "E");
    }
    while (s.find("Der") != std::string::npos) {
        s.replace(s.find("Der"), 3, "");
    }
    while (s.find("Er") != std::string::npos) {
        s.replace(s.find("Er"), 2, "");
    }
    while (s.find("D") != std::string::npos) {
        s.replace(s.find("D"), 1, "");
    }
    while (s.find("E") != std::string::npos) {
        s.replace(s.find("E"), 1, "");
    }

    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    if (s.empty()) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

// 
