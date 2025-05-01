cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input_line;
    std::getline(std::cin, input_line);
    std::istringstream input_stream(input_line);
    
    int result = 0;
    int input_value;
    while (input_stream >> input_value) {
        result++;
        if (input_value == 0) {
            break;
        }
    }
    
    std::cout << result << std::endl;
    
    return 0;
} // //End of Code


