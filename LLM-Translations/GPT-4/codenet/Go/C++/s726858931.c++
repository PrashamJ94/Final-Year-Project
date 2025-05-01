#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    char c = 'a';

    for (int j = 0; j < 26; j++) {
        bool found = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true;
                break;
            }
        }
        if (found == false) {
            std::cout << c << std::endl;
            return 0;
        }
        c++;
    }

    std::cout << "None" << std::endl;

    return 0;
}

// 
