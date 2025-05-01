#include <iostream>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::set<std::string> unique_strings;
    for (int i = 0; i < n; ++i) {
        std::string input;
        std::cin >> input;
        unique_strings.insert(input);
    }
    std::cout << unique_strings.size() << std::endl;
    return 0;
}
// 
