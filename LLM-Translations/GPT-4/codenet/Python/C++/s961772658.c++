#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;
    std::vector<char> alphabets = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < alphabets.size(); i++) {
        if (alphabets[i] == s[0]) {
            std::cout << alphabets[i + 1] << std::endl;
            break;
        }
    }
    return 0;
}
// 
