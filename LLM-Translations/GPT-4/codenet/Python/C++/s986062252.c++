#include <iostream>
#include <algorithm>
#include <string>

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    int aa = gcd(n, m);
    int bb = lcm(n, m);
    int cc = aa / bb;
    for (int i = 0; i < aa; i++) {
        if (s[n / aa * i] != t[m / aa * i]) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << bb << std::endl;
    return 0;
}

// 
