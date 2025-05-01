#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

class atcoder_AGC029_C {
private:
    int n;
    std::vector<int> a;
    std::map<int, int> s;

public:
    void solve();

private:
    void set();
    bool isPossible(int k);
};

void atcoder_AGC029_C::set() {
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    s.clear();
}

bool atcoder_AGC029_C::isPossible(int k) {
    s.clear();
    int current = 0;
    for (int ai : a) {
        if (ai <= current) {
            if (k == 1) return false;
            while (!s.empty() && s.rbegin()->first >= ai) s.erase(s.rbegin()->first);
            int p = ai - 1;
            while (true) {
                if (p < 0) return false;
                int sp = ++s[p];
                if (sp == k) {
                    s.erase(p);
                    p--;
                } else {
                    break;
                }
            }
        }
        current = ai;
    }
    return true;
}

void atcoder_AGC029_C::solve() {
    set();
    int ng = 0;
    int ok = n;
    while (ok - ng > 1) {
        int k = (ng + ok) / 2;
        if (isPossible(k)) {
            ok = k;
        } else {
            ng = k;
        }
    }
    std::cout << ok << std::endl;
}

int main() {
    atcoder_AGC029_C m;
    m.solve();
    return 0;
}

// //End of Code
