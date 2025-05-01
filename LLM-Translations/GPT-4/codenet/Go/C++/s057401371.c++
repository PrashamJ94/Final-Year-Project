#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s;
    std::getline(std::cin, s);

    int d = 'a' - 'A';
    for (char c : s) {
        char cc = c;
        if ('A' <= c && c <= 'Z') {
            cc = c + d;
        } else if ('a' <= c && c <= 'z') {
            cc = c - d;
        }
        std::cout << cc;
    }
    std::cout << std::endl;

    return 0;
}

// 
