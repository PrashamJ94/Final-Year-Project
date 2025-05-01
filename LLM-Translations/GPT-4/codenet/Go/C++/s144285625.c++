#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ar(3 * n);
    for (int i = 0; i < 3 * n; i++) {
        std::cin >> ar[i];
    }

    sort(ar.begin(), ar.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[3 * n - (i + 1) * 2];
    }

    std::cout << sum << std::endl;

    return 0;
}
// 
