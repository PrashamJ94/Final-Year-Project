#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    int input;
    std::cin >> input;
    std::string result = "Christmas";
    for (int i = 0; i < std::abs(input - 25); ++i) {
        result += " Eve";
    }
    std::cout << result << std::endl;
    return 0;
}
// 
