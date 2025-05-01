#include <iostream>
#include <string>

int main() {
    int A, B;
    std::string B_str;
    std::cin >> A >> B_str;

    B_str.erase(remove(B_str.begin(), B_str.end(), '.'), B_str.end());
    B = std::stoi(B_str);

    std::cout << A * B / 100 << std::endl;

    return 0;
}
// 
