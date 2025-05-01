#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

class IntegralRect {
public:
    int height;
    int width;
    IntegralRect(int h, int w) : height(h), width(w) {}

    int diagonal() {
        if (height >= width) {
            return INT32_MAX;
        }
        return height * height + width * width;
    }

    bool operator<(const IntegralRect &other) const {
        int d1 = this->diagonal();
        int d2 = other.diagonal();
        return d1 == d2 ? this->height < other.height : d1 < d2;
    }
};

int main() {
    std::vector<IntegralRect> rects;
    rects.reserve(40000);
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects.emplace_back(i + 1, j + 1);
        }
    }
    std::sort(rects.begin(), rects.end());

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int h, w;
        iss >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect(h, w);
        for (const auto &rect : rects) {
            if (rect < tmpRect) {
                continue;
            }
            std::cout << rect.height << " " << rect.width << std::endl;
            break;
        }
    }

    return 0;
}

// 
