#include <iostream>
#include <vector>
#include <algorithm>

struct work {
    int time, limit;
};

bool compare_works(const work& a, const work& b) {
    return a.limit < b.limit;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<work> ws(n);
    
    for (int i = 0; i < n; i++) {
        int a, n;
        std::cin >> a >> n;
        ws[i] = {a, n};
    }
    
    std::sort(ws.begin(), ws.end(), compare_works);

    int64_t sum = 0;
    for (const auto& w : ws) {
        sum += w.time;
        if (sum > w.limit) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
// 
