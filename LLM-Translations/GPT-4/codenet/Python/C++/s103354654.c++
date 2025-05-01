#include <iostream>

int main() {
    int W, H, x, y, r;
    std::cin >> W >> H >> x >> y >> r;

    if (x >= r && (W - r) >= x) {
        if (y >= r && (H - r) >= y) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
} // 
