#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::string> b;
    for (int i = n - 1; i >= 0; i -= 2) {
        b.push_back(a[i]);
    }
    for (int i = n % 2; i < n; i += 2) {
        b.push_back(a[i]);
    }

    if (n % 2 == 0) {
        std::copy(b.begin(), b.end(), std::ostream_iterator<std::string>(std::cout, " "));
    } else {
        std::copy(b.rbegin(), b.rend(), std::ostream_iterator<std::string>(std::cout, " "));
    }

    std::cout << std::endl;

    return 0;
} // 
