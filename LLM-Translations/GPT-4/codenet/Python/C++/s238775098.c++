#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    double res = 0;
    for (int i = 0; i < n; ++i) {
        double x;
        std::string u;
        std::cin >> x >> u;
        if (u == "BTC") {
            res += x * 380000;
        } else {
            res += x;
        }
    }
    std::cout << res << std::endl;
    return 0;
} // 
