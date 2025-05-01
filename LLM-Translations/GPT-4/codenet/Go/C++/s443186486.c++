#include <iostream>
#include <vector>
#include <algorithm>

int combi(int n, int r) {
    int c = 1;
    for (int i = 1; i <= r; i++) {
        c = c * (n - i + 1) / i;
    }
    return c;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    std::sort(s.begin(), s.end());

    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) {
            count++;
        } else if (count > 0) {
            ans += combi(count + 1, 2);
            count = 0;
        }
    }
    if (count > 0) {
        ans += combi(count + 1, 2);
    }

    std::cout << ans << std::endl;

    return 0;
}

// 
