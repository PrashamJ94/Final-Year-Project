#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

int main() {
    std::map<int, int> m;
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        m[a]++;
    }
    for (int i = 0; i < M; i++) {
        int B, C;
        std::cin >> B >> C;
        m[C] += B;
    }
    std::vector<int> ints;
    for (const auto &x : m) {
        ints.push_back(x.first);
    }
    std::sort(ints.begin(), ints.end(), std::greater<int>());
    int rest = N;
    int sum = 0;
    for (const auto &i : ints) {
        int num = m[i];
        if (num >= rest) {
            sum += rest * i;
            break;
        }
        sum += num * i;
        rest -= num;
    }
    std::cout << sum << std::endl;
    return 0;
}

// 
