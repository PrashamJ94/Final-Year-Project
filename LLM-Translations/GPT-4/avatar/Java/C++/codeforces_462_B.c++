#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class c462b {
public:
    int left = 0;

    bool operator<(const c462b& other) const {
        return left < other.left;
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<c462b> cards(26);
    std::string s;
    std::cin >> s;

    for (int t = 0; t < n; t++) {
        cards[s[t] - 'A'].left++;
    }

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        std::sort(cards.rbegin(), cards.rend());
        long long change = std::min(cards[0].left, k - i);
        ans += change * change;
        cards[0].left -= change;
        i += change - 1;
    }

    std::cout << ans << std::endl;
    return 0;
}

// //End of Code.
