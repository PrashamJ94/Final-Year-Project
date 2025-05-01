#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> getPoints(int n, int k, int l, int r, int sAll, int sk) {
    std::vector<int> ans(n, l);
    sAll -= sk + (n - k) * l;
    sk -= k * l;

    while (sk > 0) {
        int idx = n - 1;
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++;
            sk--;
        }
    }

    while (sAll > 0) {
        int idx = 0;
        while (sAll > 0 && idx < n - k) {
            ans[idx++]++;
            sAll--;
        }
    }

    return ans;
}

int main() {
    int n, k, l, r, sAll, sk;
    std::cin >> n >> k >> l >> r >> sAll >> sk;

    std::vector<int> ans = getPoints(n, k, l, r, sAll, sk);
    for (int num : ans) {
        std::cout << num << " ";
    }

    return 0;
}

// //End of Code.
