
#include <iostream>
#include <string>

int keta(std::string s) {
    if (s.length() < 2) {
        return std::stoi(s);
    }
    int n = 0;
    for (char c : s) {
        n += c - '0';
    }
    return keta(std::to_string(n));
}

int main() {
    std::string N;
    std::cin >> N;

    if (keta(N) % 9 == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}


