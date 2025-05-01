#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int sa = count(s.begin(), s.end(), '-');
    sa = min(n - sa, sa);
    vector<string> ss;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        b -= a;
        ss.push_back((b % 2 && b <= sa * 2) ? "1\n" : "0\n");
    }
    for(const auto &str : ss)
        cout << str;
    return 0;
} // End of Code
