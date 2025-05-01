#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string sage;
    std::getline(std::cin, sage);

    if (sage == "1") {
        std::cout << "Hello World" << std::endl;
    } else if (sage == "2") {
        int sum = 0;
        for (int i = 0; i < 2; ++i) {
            std::string input;
            int num;
            std::getline(std::cin, input);
            std::stringstream(input) >> num;
            sum += num;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}
// 
