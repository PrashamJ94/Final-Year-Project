#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::unordered_set<int> set;
    int num;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        set.insert(num);
    }
    std::cout << set.size() << std::endl;

    return 0;
}

// 
