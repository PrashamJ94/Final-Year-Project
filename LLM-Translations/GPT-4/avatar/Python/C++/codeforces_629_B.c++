#include <iostream>
#include <vector>

int main() {
    const int N = 368;
    std::vector<int> m(N, 0);
    std::vector<int> f(N, 0);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        char x;
        int a, b;
        std::cin >> x >> a >> b;
        b = b + 1;
        if (x == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < N; i++) {
        a += m[i];
        b += f[i];
        if (std::min(a, b) > c) {
            c = std::min(a, b);
        }
    }
    std::cout << c << std::endl;
    return 0;
} // End of Code
