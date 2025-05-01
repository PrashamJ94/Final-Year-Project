#include <iostream>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::replace( input.begin(), input.end(), ',', ' ');
    std::cout << input;
    return 0;
}

// End of Code
