#include <iostream>
#include <vector>
#include <algorithm>

int solution(int n, std::vector<int>& a) {
    std::vector<int> memo(1e5 + 2, 0);
    for (int num : a) {
        memo[num]++;
        memo[num + 1]++;
        memo[num + 2]++;
    }
    int out = 0;
    for (int num : memo) {
        if (num > 0) {
            out = std::max(out, num);
        }
    }
    return out;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cout << solution(n, a) << std::endl;
    return 0;
}
// 
