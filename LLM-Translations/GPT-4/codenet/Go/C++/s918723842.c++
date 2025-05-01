
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int max(int a, int b) {
    if (a < b) {
        return b;
    }
    return a;
}

int main() {
    int H, W, N;
    std::cin >> H >> W >> N;

    int A = max(H, W);

    std::cout << (N + A - 1) / A << std::endl;

    return 0;
}

// 
