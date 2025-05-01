
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

double AbsDiffDouble(double n1, double n2) {
    return std::abs(n1 - n2);
}

int main() {
    int n;
    double t, a;
    std::cin >> n >> t >> a;

    std::vector<double> heights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    double minDiff = AbsDiffDouble(t - heights[0] * 0.006, a);
    int minIdx = 0;
    for (int i = 1; i < n; i++) {
        double diff = AbsDiffDouble(t - heights[i] * 0.006, a);
        if (diff < minDiff) {
            minDiff = diff;
            minIdx = i;
        }
    }

    std::cout << minIdx + 1 << std::endl;

    return 0;
}

// 
