#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string result = "";
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '.') {
            result += '0';
        } else {
            i += 1;
            if (s[i] == '.') {
                result += '1';
            } else {
                result += '2';
            }
        }
        i += 1;
    }
    std::cout << result;
    return 0;
}
// End of Code
