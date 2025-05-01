#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::string S, T;
    std::cin >> S >> T;

    std::vector<char> char_lists;

    for (int i = 0; i < N; ++i) {
        char_lists.push_back(S[i]);
        char_lists.push_back(T[i]);
    }

    for (const char &c : char_lists) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
} // 
