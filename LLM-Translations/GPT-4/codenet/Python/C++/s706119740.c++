
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> candy(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> candy[i];
    }
    std::sort(candy.begin(), candy.end());
    
    if (candy[0] + candy[1] == candy[2]) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}
// 


