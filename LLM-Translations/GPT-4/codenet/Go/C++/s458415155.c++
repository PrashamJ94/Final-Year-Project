
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

int iabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int solve(int n, std::vector<int>& heights) {
    std::vector<int> t(n + 1, std::numeric_limits<int>::max());

    t[0] = 0;
    for (int i = 1; i < n; i++) {
        if (int v = t[i - 1] + iabs(heights[i] - heights[i - 1]); v < t[i]) {
            t[i] = v;
        }
        if (1 < i) {
            if (int v = t[i - 2] + iabs(heights[i] - heights[i - 2]); v < t[i]) {
                t[i] = v;
            }
        }
    }

    return t[n - 1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }
    int ans = solve(n, heights);
    std::cout << ans << std::endl;
}

// 
