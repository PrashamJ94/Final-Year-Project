#include <iostream>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;
    int x = m * 1900 + (n - m) * 100;
    std::cout << x * int(std::pow(2.0, double(m))) << std::endl;
    return 0;
}

// 
