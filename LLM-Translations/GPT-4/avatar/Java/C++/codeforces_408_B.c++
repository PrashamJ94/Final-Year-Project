#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

bool isValid(const std::string& s1, const std::string& s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    std::unordered_map<char, bool> map;

    for (char c : s1) {
        map[c] = true;
    }

    for (char c : s2) {
        if (map.find(c) == map.end()) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    if (!isValid(s1, s2)) {
        std::cout << -1 << std::endl;
    } else {
        std::unordered_map<char, int> m1, m2;

        for (char c : s1) {
            m1[c]++;
        }

        for (char c : s2) {
            m2[c]++;
        }

        int ans = 0;
        std::unordered_set<char> hs;

        for (char c : s2) {
            if (hs.find(c) == hs.end()) {
                hs.insert(c);
                int x1 = m1[c];
                int x2 = m2[c];
                x1 = std::min(x1, x2);
                ans += x1;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}

// //End of Code
