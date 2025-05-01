#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int A, B;
    std::string S;
    std::cin >> A >> B;
    std::cin.ignore();
    std::getline(std::cin, S);

    if (S[A] == '-' && std::count(S.begin(), S.end(), '-') == 1) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
} // 
