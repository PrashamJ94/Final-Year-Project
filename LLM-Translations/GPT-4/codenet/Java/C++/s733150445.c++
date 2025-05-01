#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    double a, b;
    iss >> a >> b;
    double mul = a * b;
    std::cout << std::fixed << std::setprecision(0) << mul << std::endl;
    return 0;
}

// 
