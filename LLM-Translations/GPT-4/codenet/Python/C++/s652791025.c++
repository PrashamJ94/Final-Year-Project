#include <iostream>
#include <string>

int main() {
    std::string n;
    std::cin >> n;
    int last_digit = n.back() - '0';

    if (last_digit == 2 || last_digit == 4 || last_digit == 5 || last_digit == 7 || last_digit == 9) {
        std::cout << "hon" << std::endl;
    } else if (last_digit == 0 || last_digit == 1 || last_digit == 6 || last_digit == 8) {
        std::cout << "pon" << std::endl;
    } else {
        std::cout << "bon" << std::endl;
    }

    return 0;
}
// 
