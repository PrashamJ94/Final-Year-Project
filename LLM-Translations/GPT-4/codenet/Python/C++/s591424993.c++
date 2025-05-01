#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

int main() {
    int d, g;
    std::cin >> d >> g;
    std::vector<std::pair<int, int>> pc(d);
    for (int i = 0; i < d; ++i) {
        std::cin >> pc[i].first >> pc[i].second;
    }

    int ans = std::numeric_limits<int>::max();

    for (int bit = 0; bit < (1 << d); ++bit) {
        int count = 0;
        int sum = 0;
        std::set<int> nokori;
        for (int i = 1; i <= d; ++i) {
            nokori.insert(i);
        }

        for (int i = 0; i < d; ++i) {
            if (bit & (1 << i)) {
                sum += pc[i].first * (i + 1) * 100 + pc[i].second;
                count += pc[i].first;
                nokori.erase(i + 1);
            }
        }

        if (sum < g) {
            int use = *nokori.rbegin();
            int n = std::min(pc[use-1].first, -((g - sum) / (use * 100)));
            count += n;
            sum += n * use * 100;
        }

        if (sum >= g) {
            ans = std::min(ans, count);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
// 
