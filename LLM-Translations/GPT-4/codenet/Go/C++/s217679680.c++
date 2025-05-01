#include <iostream>
#include <sstream>
#include <vector>

std::vector<int> scanArrayInt() {
    std::vector<int> ret;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    
    int i;
    while (iss >> i) {
        ret.push_back(i);
    }
    return ret;
}

int main() {
    std::vector<int> arr = scanArrayInt();
    int a = arr[0], b = arr[1];
    int tap = 0;
    int consent = 1;
    while (consent < b) {
        consent = consent + a - 1;
        tap++;
    }
    std::cout << tap << std::endl;
    return 0;
}
// 
