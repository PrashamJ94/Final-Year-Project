#include <iostream>
#include <vector>

double ave(const std::vector<double>& s) {
    double sum = 0;
    for (const auto& v : s) {
        sum += v;
    }
    return sum / static_cast<double>(s.size());
}

double diff(double a, double b) {
    return a > b ? a - b : b - a;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    double average = ave(a);

    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; ++i) {
        double currentDiff = diff(a[i], average);
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            ansIndex = i;
        }
    }
    std::cout << ansIndex << std::endl;

    return 0;
}

// 
