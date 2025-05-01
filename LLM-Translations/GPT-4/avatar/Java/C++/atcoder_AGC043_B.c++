#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>

class AtCoder_AGC043_B {
public:
    int cal(const std::string &s, char c) {
        int n = s.length();
        int m = n - 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c && (m & i) == i) {
                ans ^= 1;
            }
        }
        return ans;
    }

    void solve() {
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        std::string sb;
        for (int i = 1; i < n; ++i) {
            sb.push_back(std::abs(s[i] - s[i - 1]));
        }
        if (n == 2) {
            std::cout << sb[0] << std::endl;
            return;
        }
        s = sb;
        if (s.find('1') != std::string::npos) {
            std::cout << cal(s, '1') << std::endl;
        }
        else {
            std::cout << cal(s, '2') * 2 << std::endl;
        }
    }
};

int main() {
    AtCoder_AGC043_B().solve();
    return 0;
}

// //End of Code.
