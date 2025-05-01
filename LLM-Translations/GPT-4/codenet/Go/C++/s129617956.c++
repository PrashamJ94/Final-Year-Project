#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

int min(int i, int j) {
    if (i > j) {
        return j;
    }
    return i;
}

int main() {
    int n;
    std::cin >> n;
    int rt = int(sqrt(double(n)));
    int minf = 100;
    for (int i = 1; i < rt + 1; i++) {
        if (n % i == 0) {
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            minf = min(minf, ndigit);
        }
    }
    std::cout << minf << std::endl;
    return 0;
}

// 
