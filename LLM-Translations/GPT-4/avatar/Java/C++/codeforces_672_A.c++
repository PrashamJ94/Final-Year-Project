#include <iostream>
#include <string>
#include <sstream>

std::string generateString() {
    std::stringstream ss;
    for (int i = 1; i <= 1000; i++) {
        ss << i;
    }
    return ss.str();
}

int main() {
    int n;
    std::cin >> n;
    std::string s = generateString();
    std::cout << s[n - 1] << std::endl;
    return 0;
}

// //End of Code
