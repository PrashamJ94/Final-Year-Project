#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

int main() {
    int n, d;
    std::cin >> n >> d;
    int cnt = 0;

    std::string input;
    std::getline(std::cin, input); // To consume the newline character after reading n and d

    for(int i = 0; i < n; i++) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        double x, y;
        iss >> x >> y;
        if(std::sqrt(x * x + y * y) <= d) {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
// 
