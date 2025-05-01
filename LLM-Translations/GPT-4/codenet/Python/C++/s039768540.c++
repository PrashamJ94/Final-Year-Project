#include <iostream>
#include <string>

int main() {
    int x;
    std::cin >> x;
    std::string result = "ai1333" + std::string(x / 100, '3');
    std::cout << result << std::endl;

    return 0;
} // 
