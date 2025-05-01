#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::string s;
    int l = 2019;
    std::cin >> s;

    std::vector<int> m(l+1); 
    m[0] = 1;

    int a = 0, r = 0;

    for (int i = 0; i < s.size(); ++i) {
        a += (s[s.size() - 1 - i] - '0') * std::pow(10, i) % l;
        r += m[a % l]++;
    }

    std::cout << r;

    return 0;
}

//End of Code.
