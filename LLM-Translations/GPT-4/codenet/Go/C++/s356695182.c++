#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int min(int a, int b, int c) {
    return std::min(a, std::min(b, c));
}

int max(int a, int b) {
    return std::max(a, b);
}

int pattern1(std::vector<int> &l) {
    int n = (l[0] * l[3]) + (l[1] * l[4]);
    return n;
}

int pattern2(std::vector<int> &l) {
    int n = 2 * l[2] * max(l[3], l[4]);
    return n;
}

int pattern3(std::vector<int> &l) {
    int n = 2 * l[2] * std::min(l[3], l[4]) + doch(l);
    return n;
}

int doch(std::vector<int> &l) {
    if (l[3] > l[4]) {
        return l[0] * (l[3] - l[4]);
    } else {
        return l[1] * (l[4] - l[3]);
    }
}

int main() {
    int len = 5;
    std::vector<int> l(len);
    for (int i = 0; i < len; i++) {
        std::cin >> l[i];
    }
    std::cout << min(pattern1(l), pattern2(l), pattern3(l)) << std::endl;
    return 0;
}
// 
