#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> mods(s.size(), 0);
    std::vector<int> countRemainder(2019, 0);
    int cnt = 0;

    int m = 1;
    int mod = 0;
    for (int i = 0; i < s.size(); ++i) {
        mod += (s[s.size() - i - 1] - '0') * m;

        mod %= 2019;
        m *= 10;
        m %= 2019;

        countRemainder[mod] += 1;
    }

    countRemainder[0] += 1;

    for (int i = 0; i < 2019; ++i) {
        cnt += countRemainder[i] * (countRemainder[i] - 1) / 2;
    }

    std::cout << cnt << std::endl;

    return 0;
} // 
