#include <iostream>
#include <vector>
#include <algorithm>

void reva(std::vector<int> &b, int start, int end) {
    while (start < end) {
        std::swap(b[start], b[end]);
        start++;
        end--;
    }
}

int main() {
    int n, q, b, e;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> b >> e;
        reva(a, b, e - 1);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << a[i];
    }
    std::cout << std::endl;
    return 0;
}

// 
