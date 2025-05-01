#include <iostream>
#include <string>
#include <algorithm>

std::string Rotate(std::string str) {
    int len = str.length();
    char t = str[0];
    for (int i = 0; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = t;
    return str;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        s = Rotate(s);
        if (t == s) {
            flag = true;
            break;
        }
    }
    if (flag)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}

// 
