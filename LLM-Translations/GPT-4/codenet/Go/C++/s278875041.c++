#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a;
    std::cin >> a;

    std::replace(a.begin(), a.end(), '1', '0');
    std::replace(a.begin(), a.end(), '9', '1');
    std::replace(a.begin(), a.end(), '0', '9');
    
    std::cout << a << std::endl;

    return 0;
}
// 
