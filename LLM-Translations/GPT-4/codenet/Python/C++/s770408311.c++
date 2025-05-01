#include <iostream>
#include <set>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::set<std::string> res;
    for (int i = 0; i < n; ++i) {
        std::string a;
        std::cin >> a;
        res.insert(a);
    }
    std::cout << res.size() << std::endl;
    return 0;
} // 
