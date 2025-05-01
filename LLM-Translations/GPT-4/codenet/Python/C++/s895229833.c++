#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> H(N, 0);

    for (int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    int count_best = 0, count_tmp = 0;

    for (int i = 0; i < N - 1; i++) {
        if (H[i] >= H[i + 1]) {
            count_tmp += 1;
        } else {
            if (count_tmp > count_best) {
                count_best = count_tmp;
            }

            count_tmp = 0;
        }
    }

    if (count_tmp > count_best) {
        count_best = count_tmp;
    }

    std::cout << count_best << std::endl;
    return 0;
}
// 
