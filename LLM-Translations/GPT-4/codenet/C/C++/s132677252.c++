
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <memory>

using i32 = int32_t;
using i64 = int64_t;

const i32 mod = 1000000007;

i32 mod_pow(i32 r, i32 n) {
    i32 t = 1;
    i32 s = r;
    while (n > 0) {
        if (n & 1) t = static_cast<i64>(t) * s % mod;
        s = static_cast<i64>(s) * s % mod;
        n >>= 1;
    }
    return t;
}

struct Node {
    i32 one;
    i32 zero;
};

Node merge(std::vector<Node>& a, i32 n) {
    i64 one = 0;
    i64 zero = 1;
    i64 total = 1;
    for (i32 i = 0; i < n; ++i) {
        one = (one * a[i].zero + zero * a[i].one) % mod;
        zero = zero * a[i].zero % mod;
        total = total * (a[i].zero + a[i].one) % mod;
    }
    return {one, static_cast<i32>((total + mod - one) % mod)};
}

void run() {
    i32 n;
    std::cin >> n;
    std::vector<i32> p(n + 1), depth(n + 1), cnt(n + 1);
    cnt[0] = 1;
    for (i32 i = 1; i <= n; ++i) {
        std::cin >> p[i];
        depth[i] = depth[p[i]] + 1;
        cnt[depth[i]]++;
    }
    std::vector<std::shared_ptr<std::deque<Node>>> dp(n + 1);
    std::vector<std::deque<Node>*> child(n + 1);

    for (i32 i = n; i >= 0; --i) {
        i32 v = i;
        if (dp[v] == nullptr) {
            dp[v] = std::make_shared<std::deque<Node>>();
            dp[v]->emplace_front(Node{1, 1});
            continue;
        }
        i32 len = 0;
        for (const auto& it : dp) {
            if (it != nullptr && depth[it->first] == depth[v] + 1) {
                child[len++] = it.get();
            }
        }
        if (len > 1) {
            std::sort(child.begin(), child.begin() + len, [](const auto& a, const auto& b) {
                return a->size() > b->size();
            });
            std::vector<Node> lst(len);
            for (i32 d = 0; d < static_cast<i32>(child[1]->size()); ++d) {
                i32 j = 0;
                for (; j < len && d < static_cast<i32>(child[j]->size()); ++j) {
                    lst[j] = child[j]->at(d);
                }
                child[0]->at(d) = merge(lst, j);
            }
            for (i32 j = 1; j < len; ++j) {
                child[j] = nullptr;
            }
        }
        dp[v] = std::shared_ptr<std::deque<Node>>(child[0]);
        dp[v]->emplace_front(Node{1, 1});
    }

    i64 ans = 0;
    for (i32 i = 0; i < static_cast<i32>(dp[0]->size()); ++i) {
        ans += static_cast<i64>(mod_pow(2, n + 1 - cnt[i])) * dp[0]->at(i).one % mod;
    }
    std::cout << ans % mod << std::endl;
}

int main() {
    run();
    return 0;
}

// 
