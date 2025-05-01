#include <iostream>
#include <vector>
#include <algorithm>

int min(const std::vector<int>& nums) {
    int min = nums[0];
    for (const auto& v : nums) {
        if (v < min) {
            min = v;
        }
    }
    return min;
}

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> nums = {n * a, b};
    std::cout << min(nums) << std::endl;

    return 0;
}
// 
