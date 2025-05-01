
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::priority_queue<int> a;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        a.push(num);
    }
    
    auto dis = [](int x, int y) {
        return x / std::pow(2, y);
    };

    for (int i = 0; i < m; ++i) {
        int top = a.top();
        a.pop();
        a.push(dis(top, 1));
    }

    int sum = 0;
    while (!a.empty()) {
        sum += a.top();
        a.pop();
    }

    std::cout << -sum << std::endl;

    return 0;
}
// 


