#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string temp;
    std::string num;

    while (ss >> temp) {
        num += temp;
    }

    int numValue = std::stoi(num);

    if (numValue % 4 == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
// 
