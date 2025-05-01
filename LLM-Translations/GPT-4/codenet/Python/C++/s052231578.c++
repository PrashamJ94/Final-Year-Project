
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr = {111, 222, 333, 444, 555, 666, 777, 888, 999};
    auto ans_idx = std::lower_bound(arr.begin(), arr.end(), N);
    std::cout << *ans_idx << std::endl;
    return 0;
}


