#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string my_str = "";

    for(auto c : s) {
        if(c == '0' || c == '1') {
            my_str += c;
        }
        else if(c == 'B' && !my_str.empty()) {
            my_str = my_str.substr(0, my_str.length() - 1);
        }
    }

    std::cout << my_str;
    return 0;
} // End of Code
