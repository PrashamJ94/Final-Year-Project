#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <cstdint>
#include <cstring>

typedef int32_t i32;
typedef int64_t i64;

struct index_val {
    i32 index;
    i32 val;
};

bool cmp_index_val(const index_val &a, const index_val &b) {
    return a.val < b.val;
}

struct segment_node {
    i32 index;
    i64 val;
};

void func_segment_node(segment_node &c, const segment_node &a, const segment_node &b) {
    c = a.val < b.val ? a : b;
}

struct edge {
    i32 a, b;
    i64 c;
};

bool cmp_edge(const edge &a, const edge &b) {
    return a.c < b.c;
}

class UnionFind {
public:
    UnionFind(int32_t size) : parent(size, -1) {}

    int32_t root(int32_t x) {
        int32_t index[32];
        int32_t len = 0;
        while (parent[x] >= 0) {
            index[len++] = x;
            x = parent[x];
        }
        while (len > 0) {
            parent[index[--len]] = x;
        }
        return x;
    }

    bool same(int32_t x, int32_t y) {
        return root(x) == root(y);
    }

    int32_t getSize(int32_t x) {
        return -parent[root(x)];
    }

    void unite(int32_t x, int32_t y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (parent[x] > parent[y]) {
            std::swap(x, y);
        }
        parent[x] += parent[y];
        parent[y] = x;
    }

private:
    std::vector<int32_t> parent;
};

void run() {
    i32 n, d;
    std::cin >> n >> d;
    std::vector<i32> a(n);
    std::vector<index_val> p(n);
    for (i32 i = 0; i < n; ++i) {
        std::cin >> a[i];
        p[i] = {i, a[i]};
    }
    std::sort(p.begin(), p.end(), cmp_index_val);
    const segment_node ini = {n, static_cast<i64>(n + 2) * 1000000000 + 1};
    std::vector<segment_node> l(2 * n, ini), r(2 * n, ini);
    for (i32 i = 0; i < n; ++i) {
        l[i + n] = {i, a[i] + static_cast<i64>(n - 1 - i) * d};
        r[i + n] = {i, a[i] + static_cast<i64>(i) * d};
    }
    for (i32 i = n - 1; i > 0; --i) {
        func_segment_node(l[i], l[i * 2], l[i * 2 + 1]);
        func_segment_node(r[i], r[i * 2], r[i * 2 + 1]);
    }
    std::priority_queue<edge, std::vector<edge>, std::function<bool(const edge &, const edge &)>> h(cmp_edge);
    for (i32 i = 0; i < n; ++i) {
        i32 v = p[i].index;
        if (v > 0) {
            segment_node t;
            int pos = v;
            for (pos = pos + n; pos > 1; pos >>= 1) {
                if (pos & 1) {
                    func_segment_node(t, t, l[pos ^ 1]);
                }
            }
            h.push({v, t.index, p[i].val + t.val - static_cast<i64>(n - 1 - v) * d});
        }
        if (v + 1 < n) {
            segment_node t;
            int pos = v + 1;
            for (pos = pos + n; pos > 1; pos >>= 1) {
                if (!(pos & 1)) {
                    func_segment_node(t, t, r[pos ^ 1]);
                }
            }
            h.push({v, t.index, p[i].val + t.val - static_cast<i64>(v) * d});
        }
        l[v + n] = ini;
        r[v + n] = ini;
        for (int pos = (v + n) / 2; pos > 0; pos >>= 1) {
            func_segment_node(l[pos], l[pos * 2], l[pos * 2 + 1]);
            func_segment_node(r[pos], r[pos * 2], r[pos * 2 + 1]);
        }
    }
    i64 sum = 0;
    UnionFind u(n);
    while (u.getSize(0) < n) {
        const edge e = h.top();
        h.pop();
        if (u.same(e.a, e.b)) continue;
        u.unite(e.a, e.b);
        sum += e.c;
    }
    std::cout << sum << std::endl;
}

int main() {
    run();
    return 0;
}
// 
