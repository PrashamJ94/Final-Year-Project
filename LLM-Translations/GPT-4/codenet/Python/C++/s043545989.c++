#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    std::unordered_map<int, int> B;
    for (int i = 0; i < N; i++) {
        B[a[i]]++;
    }
    
    if (B.size() == 3) {
        std::vector<int> k;
        std::vector<int> v;
        for (const auto &p : B) {
            k.push_back(p.first);
            v.push_back(p.second);
        }
        if ((k[0] ^ k[1] ^ k[2]) == 0 && v[0] == v[1] && v[1] == v[2]) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    } else if (B.size() == 2 && B.count(0)) {
        int non_zero_key, non_zero_val;
        for (const auto &p : B) {
            if (p.first != 0) {
                non_zero_key = p.first;
                non_zero_val = p.second;
            }
        }
        if (B[0] == 2 * non_zero_val) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    } else if (B.size() == 1 && B.count(0)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
// 
