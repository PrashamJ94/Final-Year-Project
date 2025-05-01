#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <numeric>

int root(int i, std::vector<int> &uni) {
    if (i == uni[i]) {
        return i;
    }

    uni[i] = root(uni[i], uni);
    return uni[i];
}

class MP {
public:
    std::string s;
    std::vector<int> table;

    void init(const std::string &str) {
        s = str;
        int n = s.length();
        table.resize(n + 1);
        table[0] = -1;
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && s[i] != s[j]) {
                j = table[j];
            }
            j++;
            table[i + 1] = j;
        }
    }
};

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int ns = s.length();
    int nt = t.length();

    std::vector<std::string> ss((nt - 1) / ns + 1);

    for (int i = 0; i < ss.size(); i++) {
        ss[i] = s;
    }

    std::string sss = std::accumulate(std::begin(ss), std::end(ss), std::string()) + std::accumulate(std::begin(ss), std::end(ss), std::string());

    std::vector<bool> ok(ns);

    std::vector<int> uni(ns);
    std::iota(uni.begin(), uni.end(), 0);

    MP mp;
    mp.init(t);
    int m = 0;

    for (int i = 0; i < ns; i++) {
        bool o = true;
        for (; m < nt; m++) {
            if (t[m] != sss[i + m]) {
                o = false;
                break;
            }
        }
        ok[i] = o;
        if (o) {
            i += nt - mp.table[m];
            m = mp.table[m];
        }
        while (m >= 0 && t[m] != sss[i + m]) {
            i += m - mp.table[m];
            m = mp.table[m];
        }
        i--;
        m++;
    }

    int ans = 0;
    int r, rr;

    for (int i = 0; i < ns; i++) {
        if (ok[i] == false) {
            continue;
        }
        if (ok[(i + nt) % ns] == false) {
            continue;
        }
        r = root(i, uni);
        rr = root((i + nt) % ns, uni);
        if (rr == r) {
            std::cout << -1 << std::endl;
            return 0;
        }
        uni[rr] = r;
    }

    std::vector<int> counter(ns);
    for (int i = 0; i < ns; i++) {
        r = root(i, uni);
        if (ok[r] == false) {
            continue;
        }
        counter[r]++;
    }
    for (int i = 0; i < ns; i++) {
        if (ans < counter[i]) {
            ans = counter[i];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

// 
