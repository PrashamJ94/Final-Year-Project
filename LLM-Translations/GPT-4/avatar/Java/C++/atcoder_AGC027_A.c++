#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    long x;
    std::cin >> N >> x;
    std::vector<long> sweet(N);

    for (int i = 0; i < N; i++) {
        std::cin >> sweet[i];
    }

    std::sort(sweet.begin(), sweet.end());
    int num = 0;

    for (int i = 0; i < N; i++) {
        if (x - sweet[num] >= 0) {
            x = x - sweet[num];
            num++;
        } else {
            break;
        }
    }

    if ((num == N) && (x > 0)) {
        num -= 1;
    }

    std::cout << num << std::endl;
    return 0;
}

// //End of Code.
