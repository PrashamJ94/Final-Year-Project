#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string S, T;
    std::cin >> S >> T;
    int max = 0;
    for (int i = 0; i <= S.length() - T.length(); i++) {
        int c = 0;
        for (int j = 0; j < T.length(); j++) {
            if (S[i + j] == T[j]) {
                c++;
            }
        }
        if (max < c) {
            max = c;
        }
    }
    std::cout << T.length() - max << std::endl;
    return 0;
}

// 
