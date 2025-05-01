#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    std::string doubled_input = input + input;
    std::string search;
    std::cin >> search;

    if (doubled_input.find(search) != std::string::npos) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

// 
