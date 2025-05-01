#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) { return std::tolower(c) == c ? std::toupper(c) : std::tolower(c); });
    std::cout << input << std::endl;
    
    return 0;
}
// 
