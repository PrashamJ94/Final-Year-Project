#include <iostream>
#include <string>

std::string atc_079a(const std::string& input_value) {
    int n = 3;
    for (int i = 0; i < static_cast<int>(input_value.length()) + 1 - n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (input_value[i] != input_value[i + j]) {
                break;
            }
            if (j == n - 1) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    std::string input_value;
    std::cin >> input_value;
    std::cout << atc_079a(input_value) << std::endl;
    return 0;
}
// 
