#include <iostream>
#include <cmath>

int main() {
    int sec, per_num;
    double max_sec;
    std::cin >> sec >> per_num >> max_sec;
    max_sec += 0.5;
    int ans_num = 0;
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }
    std::cout << ans_num << std::endl;
    return 0;
}

// //End of Code.
