#include <iostream>
#include <vector>
#include <algorithm>

const int mod = 998244353;
const int facNum = 300001;

int main() {
    int N, sum = 0;
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}

// 
