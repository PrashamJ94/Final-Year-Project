#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void solve(std::istream &in, std::ostream &out) {
    std::string s;
    in >> s;

    std::vector<int> cum(s.length() + 1);
    cum[0] = cum[s.length()] = 0;

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            cum[i] = cum[i - 1] + 1;
        } else {
            cum[i] = cum[i - 1];
        }
    }

    int q;
    in >> q;

    while (q--) {
        int l, r;
        in >> l >> r;
        l--; r--;

        out << (cum[r] - cum[l]) << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    solve(std::cin, std::cout);

    return 0;
}
// //End of Code.
