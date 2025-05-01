#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isupper(c)) {
            c += 32;
            std::cout << c;
        } else if (islower(c)) {
            c -= 32;
            std::cout << c;
        } else {
            std::cout << c;
        }
    }
    std::cout << std::endl;

    return 0;
}

// 
