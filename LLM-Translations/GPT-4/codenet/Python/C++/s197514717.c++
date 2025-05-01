#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    std::vector<int> ABC = {A, B, C};
    int max_sum = std::max({ 10*ABC[0]+ABC[1]+ABC[2], 10*ABC[1]+ABC[2]+ABC[0], 10*ABC[2]+ABC[0]+ABC[1] });

    std::cout << max_sum << std::endl;

    return 0;
}
// 
