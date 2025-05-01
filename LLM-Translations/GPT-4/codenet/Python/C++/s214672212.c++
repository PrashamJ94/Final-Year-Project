#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums;
    int num;
    while (std::cin >> num) {
        nums.push_back(num);
    }
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    std::cout << nums[0] * 10 + nums[1] + nums[2] << std::endl;

    return 0;
}
// 
