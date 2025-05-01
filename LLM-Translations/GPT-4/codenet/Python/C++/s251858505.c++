#include <iostream>
#include <string>

int main() {
    std::string input1, input2;
    std::cin >> input1 >> input2;
    int count = 0;
    for (size_t i = 0; i < input1.size() && i < input2.size(); ++i) {
        if (input1[i] == input2[i]) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
} // 
