#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> L(N);
    for (int i = 0; i < N; i++) {
        std::cin >> L[i];
    }

    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int a = L[i];
                int b = L[j];
                int c = L[k];
                if (a == b || b == c || c == a) {
                    continue;
                }
                if (a + b > c && b + c > a && c + a > b) {
                    ans++;
                    // std::cout << "i:j:k:" << i + 1 << "," << j + 1 << "," << k + 1 << std::endl;
                }
            }
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
// 
