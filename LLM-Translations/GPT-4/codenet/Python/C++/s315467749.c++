#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> S(n);
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    }

    int q;
    std::cin >> q;
    std::vector<int> T(q);
    for (int i = 0; i < q; i++) {
        std::cin >> T[i];
    }

    int ans = 0;
    for (int i : T) {
        if (i == S.back() || i == S.front()) {
            ans += 1;
        } else {
            int left = 0;
            int right = n - 1;
            while (right - left > 1) {
                int mid = (left + right) / 2;
                if (S[mid] == i) {
                    ans += 1;
                    break;
                } else if (S[mid] < i) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
// 
