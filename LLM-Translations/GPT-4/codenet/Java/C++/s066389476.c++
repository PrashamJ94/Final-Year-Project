#include <iostream>
#include <string>

void solve(const std::string& a) {
    if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
}

int main() {
    std::string input;
    std::cin >> input;
    solve(input);
    return 0;
}

// 
