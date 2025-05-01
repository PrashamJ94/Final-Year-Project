#include <iostream>
#include <queue>
#include <vector>

int main() {
    // input
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        queue.push(num);
    }

    // process
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += queue.top();
        queue.pop();
    }

    // output
    std::cout << (queue.top() < sum ? "Yes" : "No") << std::endl;
    return 0;
}
// 
