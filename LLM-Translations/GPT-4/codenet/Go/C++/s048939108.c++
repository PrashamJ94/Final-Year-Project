#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string S;
    std::cin >> S;

    if (S.substr(0, 4) == "YAKI") {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// 
