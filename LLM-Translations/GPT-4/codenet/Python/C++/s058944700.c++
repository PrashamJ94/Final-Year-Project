#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int ans;
    if (n > k) {
        int tmp = n % k;
        if (tmp >= k - tmp) {
            ans = k - tmp;
        } else {
            ans = tmp;
        }
    } else if (n < k) {
        if (n >= k - n) {
            ans = k - n;
        } else {
            ans = n;
        }
    } else {
        ans = 0;
    }

    std::cout << ans << std::endl;

    return 0;
}
// 
