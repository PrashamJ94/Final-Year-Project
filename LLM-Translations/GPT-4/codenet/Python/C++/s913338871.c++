
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    int sum = 0;
    for (int i = N; i < a.size(); i += 2) {
        sum += a[i];
    }
    
    std::cout << sum << std::endl;
    return 0;
}

// 
