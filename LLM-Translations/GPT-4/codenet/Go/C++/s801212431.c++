#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string S;
    std::cin >> S;

    int l0 = 0, l1 = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '0') {
            l0++;
        } else {
            l1++;
        }
    }
    std::cout << 2 * std::min(l0, l1) << std::endl;

    return 0;
}
// 
