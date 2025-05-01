
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>

class Segment {
public:
    int n, h, i, chunk;
    std::vector<int> unit;
    std::vector<std::vector<int>> bucket;

    void init(int n) {
        this->n = n;
        unit.push_back(1);
        bucket.push_back(std::vector<int>(n));

        chunk = 8;
        for (int i = 0; n > 1; i++) {
            n = (n - 1) / chunk + 1;
            bucket.push_back(std::vector<int>(n));
            unit.push_back(unit[i] * chunk);
        }
        h = unit.size();
    }

    void maximize(int index, int value) {
        bucket[0][index] = value;
        for (i = 0; i < h - 1; i++) {
            int s = index - index % chunk;
            int t = s + chunk;
            if (t > static_cast<int>(bucket[i].size())) {
                t = bucket[i].size();
            }
            int parent = index / chunk;
            int max_val = 0;
            for (int j = s; j < t; j++) {
                if (max_val < bucket[i][j]) {
                    max_val = bucket[i][j];
                }
            }
            bucket[i + 1][parent] = max_val;
            index /= chunk;
        }
    }

    int top() {
        int index = 0;
        for (i = h - 2; i >= 0; i--) {
            int s = index * chunk;
            int t = s + chunk;
            if (t > static_cast<int>(bucket[i].size())) {
                t = bucket[i].size();
            }
            for (int j = s; j < t; j++) {
                if (bucket[i][j] == bucket[i + 1][index]) {
                    index = j;
                    break;
                }
            }
        }
        return index;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    Segment seg;
    seg.init(n);
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        seg.maximize(i, val);
    }
    for (int i = 0; i < m; i++) {
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] / 2);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += static_cast<int64_t>(seg.bucket[0][i]);
    }

    std::cout << ans << std::endl;

    return 0;
}


