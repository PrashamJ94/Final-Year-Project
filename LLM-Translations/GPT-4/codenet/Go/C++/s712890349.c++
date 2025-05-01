
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Block {
    std::string value;
    int len;
};

std::vector<Block> run_length(const std::string &s) {
    std::vector<Block> r;
    if (s.empty()) {
        return r;
    }
    Block t{std::string(1, s[0]), 1};
    for (size_t i = 1; i < s.length(); ++i) {
        if (t.value == std::string(1, s[i])) {
            t.len++;
        } else {
            r.push_back(t);
            t = Block{std::string(1, s[i]), 1};
        }
    }
    r.push_back(t);
    return r;
}

int max(int a, int b) {
    return b > a ? b : a;
}

int main() {
    int N, K, ans = 0;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;
    std::vector<Block> blocks = run_length(S);
    int sum = 0, zero = 0, l = 0;
    for (size_t r = 0; r < blocks.size(); ++r) {
        sum += blocks[r].len;
        if (blocks[r].value == "0") {
            zero++;
        }
        while (K < zero) {
            sum -= blocks[l].len;
            if (blocks[l].value == "0") {
                zero--;
            }
            l++;
        }
        ans = max(ans, sum);
    }
    std::cout << ans << std::endl;
    return 0;
}

// 
