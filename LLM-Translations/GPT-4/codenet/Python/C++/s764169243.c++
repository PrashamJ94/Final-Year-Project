#include <iostream>
#include <vector>
#include <cmath>

class SegmentTree {
public:
    int size;
    int default_value;
    std::vector<int> seg;

    SegmentTree(int s, int defaultValue) {
        size = 1 << (int)ceil(log2(s));
        default_value = defaultValue;
        seg.resize(2 * size - 1, defaultValue);
    }

    int segfunc(int x, int y) {
        return std::max(x, y);
    }

    void update(int k, int x) {
        k += size - 1;
        seg[k] = x;
        while (k) {
            k = (k - 1) / 2;
            seg[k] = segfunc(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }

    int query(int p, int q) {
        if (q <= p) {
            return default_value;
        }
        p += size - 1;
        q += size - 2;
        int ret = default_value;
        while (q - p > 1) {
            if (p % 2 == 0) {
                ret = segfunc(ret, seg[p]);
            }
            if (q % 2 == 1) {
                ret = segfunc(ret, seg[q]);
                q -= 1;
            }
            p = p / 2;
            q = (q - 1) / 2;
        }
        ret = segfunc(segfunc(ret, seg[p]), seg[q]);
        return ret;
    }
};

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
        ans[i] = i + 1;
    }
    SegmentTree left_seg(N, 0);
    for (int i = 0; i < N; ++i) {
        int num = a[i];
        ans[num - 1] *= i + 1 - left_seg.query(0, num);
        left_seg.update(num - 1, i + 1);
    }
    SegmentTree right_seg(N, 0);
    for (int i = 0; i < N; ++i) {
        int num = a[N - 1 - i];
        ans[num - 1] *= i + 1 - right_seg.query(0, num);
        right_seg.update(num - 1, i + 1);
    }
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += ans[i];
    }
    std::cout << sum << std::endl;

    return 0;
}

// 
