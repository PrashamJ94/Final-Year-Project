#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int min = std::numeric_limits<int>::max();
    int countNegatives = 0;
    long sum = 0;
    for (int num : nums) {
        int abs = std::abs(num);
        sum += abs;
        min = std::min(min, abs);
        if (num < 0) {
            countNegatives++;
        }
    }

    std::cout << (countNegatives % 2 == 0 ? sum : sum - (min * 2)) << std::endl;

    return 0;
}
// 
