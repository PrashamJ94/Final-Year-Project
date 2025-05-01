#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    if (S == "Sunny") std::cout << "Cloudy" << std::endl;

    if (S == "Cloudy") std::cout << "Rainy" << std::endl;

    if (S == "Rainy") std::cout << "Sunny" << std::endl;

    return 0;
} // 
