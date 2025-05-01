#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    double prev = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prev = (prev + arr[i]) / 2;
    }

    std::cout << prev << std::endl;
    return 0;
}

// 
