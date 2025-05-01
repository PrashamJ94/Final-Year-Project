
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> capacity_list(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> capacity_list[i];
    }
    std::sort(capacity_list.begin(), capacity_list.end());
    int bottle_neck = capacity_list[0];
    std::cout << 4 + (N + bottle_neck - 1) / bottle_neck << std::endl;

    return 0;
}
// 


