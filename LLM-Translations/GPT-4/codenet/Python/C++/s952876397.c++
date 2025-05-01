#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;

    std::cin >> n;
    std::cin >> s;

    int left = 0;
    for (char i : s) {
        if (i == ')') {
            left++;
        } else {
            break;
        }
    }

    int left1 = 0;
    int right1 = 0;

    for (int i = left; i < n; i++) {
        if (s[i] == '(') {
            right1++;
        } else if (right1 > 0) {
            right1--;
        } else {
            left1++;
        }
    }

    left1 += left;
    for (int i = 0; i < right1; i++) {
        s += ")";
    }
    for (int i = 0; i < left1; i++) {
        s = "(" + s;
    }

    std::cout << s << std::endl;

    return 0;
}
// 
