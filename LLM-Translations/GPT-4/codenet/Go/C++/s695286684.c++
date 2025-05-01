#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    std::replace(s.begin(), s.end(), '2017', '2018');
    std::cout << s << std::endl;
    return 0;
}
// 
