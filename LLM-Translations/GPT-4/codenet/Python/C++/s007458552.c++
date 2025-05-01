#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int n;
    std::string S;
    std::unordered_map<char, int> C;

    std::cin >> n;
    std::cin >> S;

    for (const char& c : S) {
        C[c]++;
    }

    std::cout << (C['R'] > n - C['R'] ? "Yes" : "No") << std::endl;

    return 0;
}

// 
